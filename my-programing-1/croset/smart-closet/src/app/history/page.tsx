"use client";

import { useEffect, useState } from "react";
import { useAuth } from "@/lib/AuthContext";
import { getLogs, getItems } from "@/lib/storage";
import { WearLog, ClothingItem } from "@/lib/types";
import {
  format,
  startOfMonth,
  endOfMonth,
  eachDayOfInterval,
  getDay,
  addMonths,
  subMonths,
  isSameDay,
  parseISO,
} from "date-fns";
import { ja } from "date-fns/locale";
import { IoChevronBack, IoChevronForward } from "react-icons/io5";

export default function HistoryPage() {
  const { user } = useAuth();
  const [currentMonth, setCurrentMonth] = useState(new Date());
  const [logs, setLogs] = useState<WearLog[]>([]);
  const [itemMap, setItemMap] = useState<Map<string, ClothingItem>>(new Map());
  const [selectedDate, setSelectedDate] = useState<string | null>(null);

  useEffect(() => {
    if (!user) return;
    setLogs(getLogs());
    const map = new Map<string, ClothingItem>();
    getItems().forEach((item) => map.set(item.id, item));
    setItemMap(map);
  }, [user]);

  const monthStart = startOfMonth(currentMonth);
  const monthEnd = endOfMonth(currentMonth);
  const days = eachDayOfInterval({ start: monthStart, end: monthEnd });
  const startDayOfWeek = getDay(monthStart);

  const logsByDate = new Map<string, WearLog>();
  logs.forEach((log) => logsByDate.set(log.date, log));

  const selectedLog = selectedDate ? logsByDate.get(selectedDate) : null;
  const selectedItems = selectedLog
    ? selectedLog.itemIds.map((id) => itemMap.get(id)).filter(Boolean) as ClothingItem[]
    : [];

  const weekDays = ["日", "月", "火", "水", "木", "金", "土"];

  if (!user) return null;

  return (
    <div className="px-4 pt-6 animate-fade-in">
      <h1 className="text-2xl font-bold mb-4">History</h1>

      <div className="flex items-center justify-between mb-4">
        <button
          onClick={() => setCurrentMonth(subMonths(currentMonth, 1))}
          className="p-2 rounded-full hover:bg-gray-100"
        >
          <IoChevronBack size={20} />
        </button>
        <span className="font-bold text-lg">
          {format(currentMonth, "yyyy年M月", { locale: ja })}
        </span>
        <button
          onClick={() => setCurrentMonth(addMonths(currentMonth, 1))}
          className="p-2 rounded-full hover:bg-gray-100"
        >
          <IoChevronForward size={20} />
        </button>
      </div>

      <div className="bg-white rounded-3xl p-4 shadow-sm mb-4">
        <div className="grid grid-cols-7 gap-1 mb-2">
          {weekDays.map((d, i) => (
            <div
              key={d}
              className={`text-center text-[11px] font-medium ${
                i === 0 ? "text-red-400" : i === 6 ? "text-blue-400" : "text-gray-400"
              }`}
            >
              {d}
            </div>
          ))}
        </div>
        <div className="grid grid-cols-7 gap-1">
          {Array.from({ length: startDayOfWeek }).map((_, i) => (
            <div key={`empty-${i}`} />
          ))}
          {days.map((day) => {
            const dateStr = format(day, "yyyy-MM-dd");
            const hasLog = logsByDate.has(dateStr);
            const isSelected = selectedDate === dateStr;
            const isToday = isSameDay(day, new Date());

            return (
              <button
                key={dateStr}
                onClick={() => setSelectedDate(isSelected ? null : dateStr)}
                className={`aspect-square flex flex-col items-center justify-center rounded-xl text-sm transition-all ${
                  isSelected
                    ? "bg-violet-600 text-white"
                    : isToday
                    ? "bg-violet-50 text-violet-600 font-bold"
                    : "text-gray-700 hover:bg-gray-50"
                }`}
              >
                <span>{format(day, "d")}</span>
                {hasLog && (
                  <div
                    className={`w-1.5 h-1.5 rounded-full mt-0.5 ${
                      isSelected ? "bg-white" : "bg-violet-400"
                    }`}
                  />
                )}
              </button>
            );
          })}
        </div>
      </div>

      {selectedDate && (
        <div className="bg-white rounded-3xl p-5 shadow-sm animate-fade-in">
          <h3 className="font-bold text-sm mb-3">
            {format(parseISO(selectedDate), "M月d日(E)", { locale: ja })}のコーデ
          </h3>
          {selectedItems.length > 0 ? (
            <div className="grid grid-cols-4 gap-2">
              {selectedItems.map((item) => (
                <div
                  key={item.id}
                  className="aspect-square bg-gray-50 rounded-xl overflow-hidden"
                >
                  <img
                    src={item.imageUrl}
                    alt={item.category}
                    className="w-full h-full object-contain p-1"
                  />
                </div>
              ))}
            </div>
          ) : (
            <p className="text-gray-400 text-sm">記録がありません</p>
          )}
        </div>
      )}
    </div>
  );
}
