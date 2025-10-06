# -*- Sub Makefile -*-
# Enhanced version with .o in build/, auto-run, and file listing
# Time-stamp: <2025-10-06>

CC := gcc
CFLAGS := -Wall -O2
LIBS := -lncurses

# Directories
B_DIR := build
I_DIR := include
E_DIR := exe

# Auto-create directories
$(shell mkdir -p $(B_DIR) $(I_DIR) $(E_DIR))

# ========================
# 🔧 Build: make file=xxx.c
# ========================
all:
	@if [ -z "$(file)" ]; then \
		echo "❌ 用法錯誤：請輸入 make file=<檔案名.c>"; \
		exit 1; \
	fi; \
	filename=$$(basename $(file) .c); \
	if [ ! -f "$(file)" ]; then \
		echo "❌ 錯誤：找不到檔案 $(file)"; \
		exit 1; \
	fi; \
	echo "🧱 建立物件檔：$(B_DIR)/$$filename.o"; \
	$(CC) $(CFLAGS) -I $(I_DIR) -c $(file) -o $(B_DIR)/$$filename.o; \
	echo "🔧 正在編譯 $$filename ..."; \
	$(CC) $(B_DIR)/$$filename.o $(LIBS) -o $(E_DIR)/$$filename && \
	echo "✅ 編譯完成：$(E_DIR)/$$filename"

# ========================
# 🚀 Run: make run file=xxx.c
# ========================
run:
	@if [ -z "$(file)" ]; then \
		echo "❌ 用法錯誤：請輸入 make run file=<檔案名.c>"; \
		exit 1; \
	fi; \
	filename=$$(basename $(file) .c); \
	if [ ! -f $(E_DIR)/$$filename ]; then \
		echo "⚙️ 找不到執行檔，正在自動編譯..."; \
		$(MAKE) file=$(file); \
	fi; \
	echo "🚀 執行 $(E_DIR)/$$filename"; \
	./$(E_DIR)/$$filename

# ========================
# 📂 List all .c files
# ========================
list:
	@echo "📂 可編譯的 .c 檔案列表："
	@files=$$(ls *.c 2>/dev/null || true); \
	if [ -z "$$files" ]; then \
		echo "（沒有找到任何 .c 檔案）"; \
	else \
		echo "$$files" | sed 's/^/ - /'; \
	fi

# ========================
# 🧹 Clean
# ========================
.PHONY: clean
clean:
	@echo "🧹 Cleaning up..."
	rm -rf $(B_DIR) $(E_DIR)
	@echo "✅ Done."

