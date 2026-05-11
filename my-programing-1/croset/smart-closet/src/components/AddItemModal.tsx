"use client";

import { useState, useRef } from "react";
import { Category } from "@/lib/types";
import { saveItem } from "@/lib/storage";
import { IoClose, IoCamera, IoImage } from "react-icons/io5";

const categories: { value: Category; label: string; emoji: string }[] = [
  { value: "tops", label: "トップス", emoji: "👕" },
  { value: "bottoms", label: "ボトムス", emoji: "👖" },
  { value: "outer", label: "アウター", emoji: "🧥" },
  { value: "shoes", label: "シューズ", emoji: "👟" },
];

const tempPresets: { label: string; min: number; max: number }[] = [
  { label: "真夏 (30℃+)", min: 28, max: 45 },
  { label: "夏 (25-30℃)", min: 23, max: 32 },
  { label: "春秋 (15-25℃)", min: 13, max: 27 },
  { label: "冬 (5-15℃)", min: 3, max: 17 },
  { label: "真冬 (~5℃)", min: -10, max: 7 },
];

interface Props {
  open: boolean;
  onClose: () => void;
  onAdded: () => void;
}

export default function AddItemModal({ open, onClose, onAdded }: Props) {
  const [preview, setPreview] = useState<string | null>(null);
  const [category, setCategory] = useState<Category>("tops");
  const [color, setColor] = useState("#000000");
  const [tempPreset, setTempPreset] = useState(2);
  const [saving, setSaving] = useState(false);
  const fileInputRef = useRef<HTMLInputElement>(null);
  const cameraInputRef = useRef<HTMLInputElement>(null);

  if (!open) return null;

  const handleFile = (file: File) => {
    const reader = new FileReader();
    reader.onload = (e) => {
      // 画像をリサイズしてbase64で保存（localStorage節約）
      const img = new Image();
      img.onload = () => {
        const canvas = document.createElement("canvas");
        const maxSize = 400;
        let w = img.width;
        let h = img.height;
        if (w > h) {
          if (w > maxSize) { h = (h * maxSize) / w; w = maxSize; }
        } else {
          if (h > maxSize) { w = (w * maxSize) / h; h = maxSize; }
        }
        canvas.width = w;
        canvas.height = h;
        canvas.getContext("2d")!.drawImage(img, 0, 0, w, h);
        setPreview(canvas.toDataURL("image/webp", 0.7));
      };
      img.src = e.target?.result as string;
    };
    reader.readAsDataURL(file);
  };

  const handleSave = () => {
    if (!preview) return;
    setSaving(true);
    const preset = tempPresets[tempPreset];
    saveItem({
      imageUrl: preview,
      category,
      color,
      tempRange: { min: preset.min, max: preset.max },
      lastWornDate: null,
    });
    setPreview(null);
    setSaving(false);
    onAdded();
    onClose();
  };

  return (
    <div className="fixed inset-0 bg-black/50 z-50 flex items-end justify-center">
      <div className="bg-white w-full max-w-md rounded-t-3xl p-6 pb-10 animate-slide-up">
        <div className="flex justify-between items-center mb-5">
          <h2 className="text-lg font-bold">アイテム追加</h2>
          <button onClick={onClose} className="p-1">
            <IoClose size={24} />
          </button>
        </div>

        {preview ? (
          <div className="relative w-full aspect-square bg-gray-50 rounded-2xl mb-4 overflow-hidden">
            <img src={preview} alt="Preview" className="w-full h-full object-contain" />
            <button
              onClick={() => setPreview(null)}
              className="absolute top-2 right-2 bg-black/50 text-white rounded-full p-1"
            >
              <IoClose size={18} />
            </button>
          </div>
        ) : (
          <div className="flex gap-3 mb-4">
            <button
              onClick={() => cameraInputRef.current?.click()}
              className="flex-1 flex flex-col items-center gap-2 py-6 bg-violet-50 rounded-2xl text-violet-600"
            >
              <IoCamera size={28} />
              <span className="text-sm font-medium">撮影</span>
            </button>
            <button
              onClick={() => fileInputRef.current?.click()}
              className="flex-1 flex flex-col items-center gap-2 py-6 bg-gray-50 rounded-2xl text-gray-600"
            >
              <IoImage size={28} />
              <span className="text-sm font-medium">アルバム</span>
            </button>
          </div>
        )}

        <input
          ref={cameraInputRef}
          type="file"
          accept="image/*"
          capture="environment"
          className="hidden"
          onChange={(e) => e.target.files?.[0] && handleFile(e.target.files[0])}
        />
        <input
          ref={fileInputRef}
          type="file"
          accept="image/*"
          className="hidden"
          onChange={(e) => e.target.files?.[0] && handleFile(e.target.files[0])}
        />

        <div className="mb-4">
          <label className="text-sm font-medium text-gray-600 mb-2 block">カテゴリ</label>
          <div className="flex gap-2">
            {categories.map((cat) => (
              <button
                key={cat.value}
                onClick={() => setCategory(cat.value)}
                className={`flex-1 py-2 rounded-xl text-sm font-medium transition-all ${
                  category === cat.value
                    ? "bg-violet-600 text-white shadow-lg shadow-violet-200"
                    : "bg-gray-100 text-gray-600"
                }`}
              >
                <span className="block text-base">{cat.emoji}</span>
                <span className="text-[10px]">{cat.label}</span>
              </button>
            ))}
          </div>
        </div>

        <div className="mb-4">
          <label className="text-sm font-medium text-gray-600 mb-2 block">適温</label>
          <div className="flex flex-wrap gap-2">
            {tempPresets.map((preset, idx) => (
              <button
                key={idx}
                onClick={() => setTempPreset(idx)}
                className={`px-3 py-1.5 rounded-full text-xs font-medium transition-all ${
                  tempPreset === idx
                    ? "bg-violet-600 text-white"
                    : "bg-gray-100 text-gray-600"
                }`}
              >
                {preset.label}
              </button>
            ))}
          </div>
        </div>

        <div className="mb-6">
          <label className="text-sm font-medium text-gray-600 mb-2 block">色</label>
          <div className="flex gap-2 items-center">
            <input
              type="color"
              value={color}
              onChange={(e) => setColor(e.target.value)}
              className="w-10 h-10 rounded-xl border-0 cursor-pointer"
            />
            <span className="text-sm text-gray-500">{color}</span>
          </div>
        </div>

        <button
          onClick={handleSave}
          disabled={!preview || saving}
          className="w-full py-3.5 bg-violet-600 text-white rounded-2xl font-bold text-base disabled:opacity-40 disabled:cursor-not-allowed transition-all active:scale-[0.98]"
        >
          {saving ? "保存中..." : "追加する"}
        </button>
      </div>
    </div>
  );
}
