"use client";

import { useEffect, useState } from "react";
import { useAuth } from "@/lib/AuthContext";
import { getItems, deleteItem } from "@/lib/storage";
import { ClothingItem, Category } from "@/lib/types";
import AddItemModal from "@/components/AddItemModal";
import { IoAdd, IoTrashOutline } from "react-icons/io5";

const tabs: { value: Category | "all"; label: string }[] = [
  { value: "all", label: "All" },
  { value: "tops", label: "👕 Tops" },
  { value: "bottoms", label: "👖 Bottoms" },
  { value: "outer", label: "🧥 Outer" },
  { value: "shoes", label: "👟 Shoes" },
];

export default function ClosetPage() {
  const { user } = useAuth();
  const [items, setItems] = useState<ClothingItem[]>([]);
  const [activeTab, setActiveTab] = useState<Category | "all">("all");
  const [showModal, setShowModal] = useState(false);

  const refreshItems = () => setItems(getItems());

  useEffect(() => {
    if (user) refreshItems();
  }, [user]);

  const handleDelete = (id: string) => {
    if (!confirm("このアイテムを削除しますか？")) return;
    deleteItem(id);
    refreshItems();
  };

  const filtered = activeTab === "all" ? items : items.filter((i) => i.category === activeTab);

  if (!user) return null;

  return (
    <div className="px-4 pt-6 animate-fade-in">
      <h1 className="text-2xl font-bold mb-4">My Closet</h1>

      <div className="flex gap-2 mb-5 overflow-x-auto hide-scrollbar pb-1">
        {tabs.map((tab) => (
          <button
            key={tab.value}
            onClick={() => setActiveTab(tab.value)}
            className={`px-4 py-2 rounded-full text-sm font-medium whitespace-nowrap transition-all ${
              activeTab === tab.value
                ? "bg-violet-600 text-white shadow-md shadow-violet-200"
                : "bg-white text-gray-600 shadow-sm"
            }`}
          >
            {tab.label}
          </button>
        ))}
      </div>

      {filtered.length === 0 ? (
        <div className="text-center py-16">
          <div className="text-5xl mb-3">🪺</div>
          <p className="text-gray-400 text-sm">アイテムがまだありません</p>
        </div>
      ) : (
        <div className="grid grid-cols-3 gap-2.5">
          {filtered.map((item) => (
            <div
              key={item.id}
              className="relative bg-white rounded-2xl overflow-hidden shadow-sm group aspect-square"
            >
              <img
                src={item.imageUrl}
                alt={item.category}
                className="w-full h-full object-contain p-2"
              />
              <div
                className="absolute top-1 right-1 w-4 h-4 rounded-full border-2 border-white shadow"
                style={{ backgroundColor: item.color }}
              />
              <button
                onClick={() => handleDelete(item.id)}
                className="absolute bottom-1 right-1 p-1.5 bg-red-500 text-white rounded-full opacity-0 group-hover:opacity-100 transition-opacity"
              >
                <IoTrashOutline size={14} />
              </button>
            </div>
          ))}
        </div>
      )}

      <button
        onClick={() => setShowModal(true)}
        className="fixed bottom-20 right-4 w-14 h-14 bg-violet-600 text-white rounded-full shadow-lg shadow-violet-300 flex items-center justify-center active:scale-90 transition-transform z-40"
      >
        <IoAdd size={28} />
      </button>

      <AddItemModal
        open={showModal}
        onClose={() => setShowModal(false)}
        onAdded={refreshItems}
      />
    </div>
  );
}
