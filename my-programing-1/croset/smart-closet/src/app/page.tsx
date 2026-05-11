"use client";

import { useEffect, useState } from "react";
import { useAuth } from "@/lib/AuthContext";
import { getItems, updateItemWornDate, addLog } from "@/lib/storage";
import { ClothingItem, WeatherData } from "@/lib/types";
import { getWeatherByLocation, getLocationAsync } from "@/lib/weather";
import { suggestOutfit } from "@/lib/suggest";
import { IoShuffle, IoCheckmarkCircle, IoLocationOutline } from "react-icons/io5";

export default function HomePage() {
  const { user, loading, login } = useAuth();
  const [weather, setWeather] = useState<WeatherData | null>(null);
  const [items, setItems] = useState<ClothingItem[]>([]);
  const [outfit, setOutfit] = useState<ReturnType<typeof suggestOutfit> | null>(null);
  const [decided, setDecided] = useState(false);
  const [nameInput, setNameInput] = useState("");

  useEffect(() => {
    if (!user) return;
    const allItems = getItems();
    setItems(allItems);

    (async () => {
      let w: WeatherData;
      try {
        const loc = await getLocationAsync();
        w = await getWeatherByLocation(loc.lat, loc.lon);
      } catch {
        w = await getWeatherByLocation(35.6762, 139.6503);
      }
      setWeather(w);
      if (allItems.length > 0) {
        setOutfit(suggestOutfit(allItems, w.tempMax));
      }
    })();
  }, [user]);

  const handleShuffle = () => {
    if (items.length === 0 || !weather) return;
    setDecided(false);
    setOutfit(suggestOutfit(items, weather.tempMax));
  };

  const handleDecide = () => {
    if (!outfit) return;
    setDecided(true);
    const today = new Date().toISOString().split("T")[0];
    const wornIds: string[] = [];

    for (const item of [outfit.tops, outfit.bottoms, outfit.outer, outfit.shoes]) {
      if (item) {
        wornIds.push(item.id);
        updateItemWornDate(item.id);
      }
    }
    addLog(today, wornIds);
  };

  if (loading) {
    return (
      <div className="flex items-center justify-center h-screen">
        <div className="w-8 h-8 border-3 border-violet-600 border-t-transparent rounded-full animate-spin" />
      </div>
    );
  }

  if (!user) {
    return (
      <div className="flex flex-col items-center justify-center h-screen px-6">
        <div className="text-6xl mb-4">👔</div>
        <h1 className="text-2xl font-bold mb-2">SmartCloset</h1>
        <p className="text-gray-500 text-sm mb-8 text-center">
          毎朝の「何着よう？」を<br />最速で解決する
        </p>
        <div className="w-full max-w-xs">
          <input
            type="text"
            value={nameInput}
            onChange={(e) => setNameInput(e.target.value)}
            placeholder="ニックネームを入力"
            className="w-full px-4 py-3 bg-white rounded-2xl shadow-sm text-center text-sm mb-3 outline-none focus:ring-2 focus:ring-violet-300"
            onKeyDown={(e) => {
              if (e.key === "Enter" && nameInput.trim()) login(nameInput.trim());
            }}
          />
          <button
            onClick={() => nameInput.trim() && login(nameInput.trim())}
            disabled={!nameInput.trim()}
            className="w-full py-3 bg-violet-600 text-white rounded-2xl font-bold text-sm disabled:opacity-40 transition-all active:scale-[0.98]"
          >
            はじめる
          </button>
        </div>
      </div>
    );
  }

  const outfitItems = outfit
    ? [outfit.tops, outfit.bottoms, outfit.outer, outfit.shoes].filter(Boolean)
    : [];

  return (
    <div className="px-4 pt-6 animate-fade-in">
      {/* 天気セクション */}
      <div className="bg-gradient-to-br from-violet-500 to-purple-600 rounded-3xl p-5 text-white mb-6 shadow-lg shadow-violet-200">
        <div className="flex items-center gap-1 text-white/70 text-xs mb-2">
          <IoLocationOutline size={14} />
          <span>{weather?.city || "取得中..."}</span>
        </div>
        <div className="flex items-center justify-between">
          <div>
            <div className="text-5xl font-bold">{weather?.temp ?? "--"}°</div>
            <div className="text-white/80 text-sm mt-1">
              最高 {weather?.tempMax ?? "--"}° / {weather?.description || "---"}
            </div>
          </div>
          {weather?.icon && (
            <img
              src={`https://openweathermap.org/img/wn/${weather.icon}@2x.png`}
              alt={weather.description}
              width={80}
              height={80}
              className="drop-shadow-lg"
            />
          )}
        </div>
      </div>

      {/* コーデ提案 */}
      <h2 className="text-lg font-bold mb-3">今日のコーデ</h2>

      {items.length === 0 ? (
        <div className="bg-white rounded-3xl p-8 text-center shadow-sm">
          <div className="text-4xl mb-3">📦</div>
          <p className="text-gray-500 text-sm">
            まだ服が登録されていません。<br />
            Closetタブからアイテムを追加しよう！
          </p>
        </div>
      ) : (
        <>
          <div className="bg-white rounded-3xl p-6 shadow-sm mb-4">
            {outfitItems.length > 0 ? (
              <div className="grid grid-cols-2 gap-3">
                {outfitItems.map((item) => (
                  <div
                    key={item!.id}
                    className="aspect-square bg-gray-50 rounded-2xl overflow-hidden relative"
                  >
                    <img
                      src={item!.imageUrl}
                      alt={item!.category}
                      className="w-full h-full object-contain p-2"
                    />
                    <span className="absolute bottom-2 left-2 text-[10px] bg-black/60 text-white px-2 py-0.5 rounded-full">
                      {item!.category}
                    </span>
                  </div>
                ))}
              </div>
            ) : (
              <p className="text-center text-gray-400 py-8">
                気温に合うアイテムがありません
              </p>
            )}
          </div>

          <div className="flex gap-3">
            <button
              onClick={handleShuffle}
              className="flex-1 flex items-center justify-center gap-2 py-4 bg-white rounded-2xl shadow-sm font-bold text-gray-700 active:scale-[0.97] transition-transform"
            >
              <IoShuffle size={22} />
              再提案
            </button>
            <button
              onClick={handleDecide}
              disabled={decided || outfitItems.length === 0}
              className={`flex-1 flex items-center justify-center gap-2 py-4 rounded-2xl font-bold active:scale-[0.97] transition-all ${
                decided
                  ? "bg-green-500 text-white"
                  : "bg-violet-600 text-white shadow-lg shadow-violet-200"
              } disabled:opacity-50`}
            >
              <IoCheckmarkCircle size={22} />
              {decided ? "決定済み!" : "これにする"}
            </button>
          </div>
        </>
      )}
    </div>
  );
}
