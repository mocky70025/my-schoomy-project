"use client";

import Link from "next/link";
import { usePathname } from "next/navigation";
import { IoHomeOutline, IoHome, IoShirtOutline, IoShirt, IoCalendarOutline, IoCalendar } from "react-icons/io5";

const navItems = [
  { href: "/", label: "Home", icon: IoHomeOutline, activeIcon: IoHome },
  { href: "/closet", label: "Closet", icon: IoShirtOutline, activeIcon: IoShirt },
  { href: "/history", label: "History", icon: IoCalendarOutline, activeIcon: IoCalendar },
];

export default function BottomNav() {
  const pathname = usePathname();

  return (
    <nav className="fixed bottom-0 left-0 right-0 bg-white/80 backdrop-blur-xl border-t border-gray-100 z-50">
      <div className="flex justify-around items-center h-16 max-w-md mx-auto">
        {navItems.map(({ href, label, icon: Icon, activeIcon: ActiveIcon }) => {
          const isActive = pathname === href;
          return (
            <Link
              key={href}
              href={href}
              className={`flex flex-col items-center gap-0.5 px-4 py-1 transition-colors ${
                isActive ? "text-violet-600" : "text-gray-400"
              }`}
            >
              {isActive ? <ActiveIcon size={24} /> : <Icon size={24} />}
              <span className="text-[10px] font-medium">{label}</span>
            </Link>
          );
        })}
      </div>
    </nav>
  );
}
