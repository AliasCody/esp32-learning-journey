# 必要部分🟢

1. ```platfomio.ini```

   - PlatformIO的設定檔案，告訴編譯器你用哪塊板子、哪種框架(Arduino / ESP-IDF)
   - 範例:

    ```ini
    [env:esp32dev]
    platform = espressif32
    board = esp32dev
    framework = arduino
    monitor_speed = 115200
    ```

2. ```week1_blinky/src/main.cpp```

   - 你的程式碼。src/ 資料夾裡的 main.cpp 會被編譯並燒錄到 ESP32。

3. ```.gitignore```

   - 告訴 Git 哪些檔案不要上傳（例如 .pio/ 編譯後檔案、暫存檔）。

4. ```README.md```

   - 說明這個專案是做什麼的、怎麼用。
   - 在 GitHub 頁面會自動顯示，讓人一看就懂。


# 進階部分🟡

   - 這些幫助你未來開 PR、記錄進度，但一開始可以先跳過：

1. ```.github/PULL_REQUEST_TEMPLATE.md```

   - 當你開 PR 時，自動幫你生成「描述、測試方式、checklist」。
用來保持 PR 一致，不會漏東西。

2. ```.github/ISSUE_TEMPLATE.md```

   - 開 Issue（回報 bug / 提需求）時會自動生成表單。
方便管理，但你自己玩時可以先不用。

3. ```templates/README_project_template.md```

   - 只是個範例 README，你未來可以複製去每個專案資料夾用。


# 專業部分🔵


1. ```.github/workflows/platformio.yml```

   - GitHub Actions 工作流程，會在你 push/PR 時自動幫你跑編譯測試。成功編譯會產生一個 firmware.bin，面試時很專業。

2. ```roadmap.md```

   - 學習路線、進度追蹤。你也可以直接用 GitHub Projects 代替。