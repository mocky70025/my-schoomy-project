import { WeatherData } from "./types";

const API_KEY = process.env.NEXT_PUBLIC_OPENWEATHER_API_KEY;

export async function getWeatherByLocation(
  lat: number,
  lon: number
): Promise<WeatherData> {
  if (!API_KEY) {
    // デモ用フォールバック
    return {
      temp: 20,
      tempMax: 24,
      description: "晴れ",
      icon: "01d",
      city: "東京",
    };
  }

  const res = await fetch(
    `https://api.openweathermap.org/data/2.5/weather?lat=${lat}&lon=${lon}&appid=${API_KEY}&units=metric&lang=ja`
  );
  const data = await res.json();

  return {
    temp: Math.round(data.main.temp),
    tempMax: Math.round(data.main.temp_max),
    description: data.weather[0].description,
    icon: data.weather[0].icon,
    city: data.name,
  };
}

export function getLocationAsync(): Promise<{ lat: number; lon: number }> {
  return new Promise((resolve, reject) => {
    if (!navigator.geolocation) {
      reject(new Error("Geolocation not supported"));
      return;
    }
    navigator.geolocation.getCurrentPosition(
      (pos) => resolve({ lat: pos.coords.latitude, lon: pos.coords.longitude }),
      (err) => reject(err)
    );
  });
}
