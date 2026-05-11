export type Category = "tops" | "bottoms" | "outer" | "shoes";

export interface ClothingItem {
  id: string;
  imageUrl: string; // base64 data URL
  category: Category;
  color: string;
  tempRange: { min: number; max: number };
  lastWornDate: number | null; // Unix ms
  createdAt: number; // Unix ms
}

export interface WearLog {
  id: string;
  date: string; // YYYY-MM-DD
  itemIds: string[];
  createdAt: number;
}

export interface WeatherData {
  temp: number;
  tempMax: number;
  description: string;
  icon: string;
  city: string;
}
