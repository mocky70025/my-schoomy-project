"use client";

import { createContext, useContext, useEffect, useState, ReactNode } from "react";
import { getProfile, saveProfile, UserProfile } from "./storage";
import { registerServiceWorker } from "./registerSW";

interface AuthContextType {
  user: UserProfile | null;
  loading: boolean;
  login: (name: string) => void;
  logout: () => void;
}

const AuthContext = createContext<AuthContextType>({
  user: null,
  loading: true,
  login: () => {},
  logout: () => {},
});

export function AuthProvider({ children }: { children: ReactNode }) {
  const [user, setUser] = useState<UserProfile | null>(null);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    registerServiceWorker();
    const profile = getProfile();
    setUser(profile);
    setLoading(false);
  }, []);

  const login = (name: string) => {
    const profile: UserProfile = { name, setupDone: true };
    saveProfile(profile);
    setUser(profile);
  };

  const logout = () => {
    localStorage.removeItem("smartcloset_profile");
    setUser(null);
  };

  return (
    <AuthContext.Provider value={{ user, loading, login, logout }}>
      {children}
    </AuthContext.Provider>
  );
}

export const useAuth = () => useContext(AuthContext);
