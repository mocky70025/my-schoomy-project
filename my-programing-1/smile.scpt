-- Google Chrome を開く
tell application "Google Chrome"
    activate
    delay 2
    make new window -- 新しいウィンドウを開く
    set URL of active tab of window 1 to "https://plicy.net/GamePlay/155561" -- 指定されたリンクを開く
end tell

delay 3 -- ページが読み込まれるのを3秒待つ

-- ゲームを開始させる
tell application "System Events"
    keystroke "\t\t\t" -- TABキーを3回押してフォーカスを移動
    delay 0.5 -- 少し待つ
    key code 36 -- Enterキーを押す（ゲーム開始）
end tell