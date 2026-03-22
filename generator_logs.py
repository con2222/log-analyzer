import random
import datetime

# Настройки генератора
NUM_LINES = 1000000
FILENAME = "test_logs.txt"

levels = ["INFO", "WARNING", "ERROR", "DEBUG"]
messages = [
    "Connection established.",
    "User authentication failed.",
    "Database timeout occurred.",
    "Disk space running low.",
    "Data successfully written to cache.",
    "Unknown packet received.",
    "Process killed by OOM killer."
]

# Чтобы ERROR встречался реже, чем INFO (имитация реальности)
weights = [0.6, 0.2, 0.1, 0.1] 

start_time = datetime.datetime(2023, 10, 25, 10, 0, 0)

print(f"Генерация {NUM_LINES} строк логов в файл {FILENAME}...")

with open(FILENAME, "w", encoding="utf-8") as f:
    for i in range(NUM_LINES):
        # Генерируем случайный уровень с учетом весов
        level = random.choices(levels, weights=weights, k=1)[0]
        msg = random.choice(messages)
        
        # Сдвигаем время вперед на случайное количество секунд
        start_time += datetime.timedelta(seconds=random.randint(1, 5))
        timestamp = start_time.strftime("%Y-%m-%d %H:%M:%S")
        
        # Формируем строку и пишем в файл
        f.write(f"[{timestamp}] [{level}] {msg}\n")

print("Готово!")
