import { ClothingItem, Category } from "./types";

export function suggestOutfit(
  items: ClothingItem[],
  tempMax: number
): { tops: ClothingItem | null; bottoms: ClothingItem | null; outer: ClothingItem | null; shoes: ClothingItem | null } {
  const twoDaysAgo = Date.now() - 2 * 24 * 60 * 60 * 1000;

  const filtered = items.filter((item) => {
    if (tempMax < item.tempRange.min || tempMax > item.tempRange.max) return false;
    if (item.lastWornDate && item.lastWornDate > twoDaysAgo) return false;
    return true;
  });

  const pickRandom = (cat: Category): ClothingItem | null => {
    const pool = filtered.filter((i) => i.category === cat);
    if (pool.length === 0) {
      const fallback = items.filter((i) => i.category === cat);
      if (fallback.length === 0) return null;
      return fallback[Math.floor(Math.random() * fallback.length)];
    }
    return pool[Math.floor(Math.random() * pool.length)];
  };

  return {
    tops: pickRandom("tops"),
    bottoms: pickRandom("bottoms"),
    outer: tempMax < 20 ? pickRandom("outer") : null,
    shoes: pickRandom("shoes"),
  };
}
