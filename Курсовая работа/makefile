# Определение компилятора и флагов компиляции
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
# -Wall включает все стандартные предупреждения
# -Wextra добавляет дополнительные проверки
# -std=c11 указывает стандарт языка (С11)
#-g добавляет отладочную информацию (для работы с отладчиком вроде GDB)

# Правило: цель all зависит от цели temp_app. При вызове make система сборки сначала попытается создать temp_app.
all: temp_app

# Правило: файл temp_app зависит от объектных файлов report.o и temp_functions.o. Чтобы собрать temp_app, сначала нужно собрать эти два объектных файла.
temp_app: report.o temp_functions.o
# Команда для сборки исполняемого файла
	$(CC) $(CFLAGS) -o temp_app report.o temp_functions.o
# $(CC) — подставляется значение переменной CC (gcc).
# $(CFLAGS) — подставляются флаги компиляции
# -o temp_app — указать имя выходного файла (temp_app).
# report.o temp_functions.o — входные объектные файлы, которые связываются в один исполняемый файл.

#  Правило: объектный файл report.o зависит от исходного файла report.c и заголовочного файла temp_functions.h
report.o: report.c temp_functions.h
# Команда для компиляции report.c в report.o
	$(CC) $(CFLAGS) -c report.c
# -c — компилировать без линковки (создать только объектный файл)

# Правило: объектный файл temp_functions.o зависит от temp_functions.c и temp_functions.h.
temp_functions.o: temp_functions.c temp_functions.h
# Компиляция temp_functions.c в объектный файл temp_functions.o.
	$(CC) $(CFLAGS) -c temp_functions.c

# Определение цели clean для удаления временных файлов
clean:
# Команда: удалить (без запросов подтверждения) исполняемый файл temp_app и объектные файлы.
	rm -f temp_app report.o temp_functions.o
# -f — игнорировать ошибки, если файлы отсутствуют.

# Указание, что цели 'all' и 'clean' не являются именами реальных файлов
.PHONY: all clean