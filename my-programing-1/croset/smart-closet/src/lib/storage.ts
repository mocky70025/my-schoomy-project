import { ClothingItem, WearLog, Category } from "./types";

const ITEMS_KEY = "smartcloset_items";
const LOGS_KEY = "smartcloset_logs";
const PROFILE_KEY = "smartcloset_profile";

// --- アイテム ---

export function getItems(): ClothingItem[] {
  if (typeof window === "undefined") return [];
  const raw = localStorage.getItem(ITEMS_KEY);
  return raw ? JSON.parse(raw) : [];
}

export function saveItem(item: Omit<ClothingItem, "id" | "createdAt">): ClothingItem {
  const items = getItems();
  const newItem: ClothingItem = {
    ...item,
    id: crypto.randomUUID(),
    createdAt: Date.now(),
  };
  items.push(newItem);
  localStorage.setItem(ITEMS_KEY, JSON.stringify(items));
  return newItem;
}

export function deleteItem(id: string) {
  const items = getItems().filter((i) => i.id !== id);
  localStorage.setItem(ITEMS_KEY, JSON.stringify(items));
}

export function updateItemWornDate(id: string) {
  const items = getItems().map((i) =>
    i.id === id ? { ...i, lastWornDate: Date.now() } : i
  );
  localStorage.setItem(ITEMS_KEY, JSON.stringify(items));
}

// --- 着用ログ ---

export function getLogs(): WearLog[] {
  if (typeof window === "undefined") return [];
  const raw = localStorage.getItem(LOGS_KEY);
  return raw ? JSON.parse(raw) : [];
}

export function addLog(date: string, itemIds: string[]) {
  const logs = getLogs();
  logs.push({
    id: crypto.randomUUID(),
    date,
    itemIds,
    createdAt: Date.now(),
  });
  localStorage.setItem(LOGS_KEY, JSON.stringify(logs));
}

// --- プロフィール ---

export interface UserProfile {
  name: string;
  setupDone: boolean;
}

export function getProfile(): UserProfile | null {
  if (typeof window === "undefined") return null;
  const raw = localStorage.getItem(PROFILE_KEY);
  return raw ? JSON.parse(raw) : null;
}

export function saveProfile(profile: UserProfile) {
  localStorage.setItem(PROFILE_KEY, JSON.stringify(profile));
}
