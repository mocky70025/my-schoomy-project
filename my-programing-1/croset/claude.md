# Smart closetの作成が主目的です。
## ターゲットである高校生にデザインが好まれるようにしてください。

###
最終確定仕様書：SmartCloset (スマートクローゼット)〜 毎朝の「何着よう？」を最速で解決する、WebベースのAIスタイリスト 〜1. プロジェクト概要ビジョン: 「服を選ぶ」という日常の意思決定コストをAIとデータで最小化する。形態: Webアプリ（PWA）。Firebase Hostingで配信し、スマホのホーム画面に追加してフルスクリーンで利用。主要ターゲット: 毎朝の準備を時短したい人、持ち服のマンネリ化を防ぎたい人。2. 技術スタック（確定）区分選定技術備考FrameworkNext.js (App Router)高速描画・PWA適正。StylingTailwind CSSモバイルファースト設計。BackendFirebaseAuth, Firestore, Storage をフル活用。DeploymentFirebase HostingGitHub Actionsによる自動デプロイを想定。External APIOpenWeatherMapリアルタイム気象データ（最高気温）の取得。Image Processremove.bg API等背景削除・アイテムの透過画像化。3. 核心的機能と詳細ロジック① クローゼット管理（アイテム登録）撮影・背景削除: ブラウザカメラで撮影。アップロード時に背景を自動除去し、他アイテムと重ね合わせ可能な「透過PNG」として保存。AI自動タグ付け: Google Cloud Vision等を併用し、画像から「カテゴリ（Tシャツなど）」「色」を自動推論。ユーザーの入力を最小化。バルクアップロード: 複数枚をまとめて撮影・一時保存し、後で一括編集できる設計。② AI提案エンジン（多層フィルタリング）人間が頭の中で行う「消去法」をアルゴリズム化する。環境フィルタ（生存）: 位置情報から当日の最高気温を取得。アイテムごとの tempRange と照合し、不適切な厚さの服を即座に除外。鮮度フィルタ（効率）: lastWornDate を参照。昨日・一昨日に着用したアイテムを除外。構成フィルタ（感性）: * 優先: 登録済みの「お気に入り全身コーデ」から適温のものを抽出。補完: 単品同士をランダムまたは色彩理論（色の相性）に基づき合成。UI: 提案をTinder風のスワイプで切り替え。決定時に履歴を更新。③ 着用ログ・カレンダー自動記録: 「これにする」ボタン押下で、選択アイテムの lastWornDate を当日で更新。カレンダー表示: Logsコレクションからデータを呼び出し、日ごとのサムネイルを表示。4. 画面設計案 (UI/UX)【Home】（最速決定画面）上部に天気・気温・推奨スタイルを表示。中央に透過画像が重なった「今日の完成コーデ」を大きく表示。下部に「決定（Check/緑）」と「再提案（Shuffle/白）」の特大ボタン。【Closet】（一覧管理）カテゴリ別タブ（All / Tops / Bottoms / Outer / Shoes）。3列グリッド表示。右下に「＋」ボタン。【History】（カレンダー）月間カレンダー。タップでその日の着用アイテム詳細を表示。5. データ構造 (Database Schema)items コレクションTypeScript{
  id: string;
  ownerId: string;
  imageUrl: string;      // 背景削除済みの透過画像
  category: "tops" | "bottoms" | "outer" | "shoes";
  tempRange: { min: number; max: number; }; // 推奨気温
  lastWornDate: Timestamp | null;
  createdAt: Timestamp;
}
coordinations コレクション（お気に入りセット）TypeScript{
  id: string;
  ownerId: string;
  name: string;
  itemIds: string[];    // itemsのIDリスト
}
6. Claude Code への最終指示用プロンプトこのままClaude Codeに貼り付けてください。SmartCloset 開発指示書:Firebase Hosting と Next.js (App Router) を使い、以下の仕様でクローゼット管理Webアプリを構築してください。1. セットアップ: > Firebase Auth (Google), Firestore, Storage の初期化。GitHub ActionsによるFirebase Hostingへの自動デプロイ設定。2. 核心ロジック:登録: ブラウザカメラ撮影。Storage保存時に背景削除APIを通し、透過PNGにする。提案: 現在地の最高気温(OpenWeatherMap)と、Firestoreの着用履歴(lastWornDate)を参照。直近2日を避けつつ、気温に最適なアイテムを抽出して提案。3. UI: > Tailwind CSS を使用。Home: 天気表示と、重なり合う服のスワイプUI。Closet: カテゴリ別グリッド表示。History: 着用履歴カレンダー。4. PWA: > サービスワーカーとmanifest.jsonを構成し、オフライン対応および「ホーム画面に追加」を可能にすること。