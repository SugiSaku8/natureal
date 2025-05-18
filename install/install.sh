#!/bin/bash

# 必要なパッケージのインストール
echo "必要なパッケージをインストール中..."
brew install cmake glew glfw glm spdlog ninja

# プロジェクトのダウンロードとビルド
echo "プロジェクトをダウンロード中..."
git clone https://github.com/your-repo/particle-engine.git
cd particle-engine

# ビルドディレクトリの作成
echo "ビルドディレクトリを作成中..."
mkdir build
cd build

# CMakeの実行
echo "CMakeを実行中..."
cmake .. -DCMAKE_BUILD_TYPE=Release -G Ninja

# ビルドの実行
echo "ビルドを実行中..."
ninja

# パス設定
echo "環境変数を設定中..."
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/engine