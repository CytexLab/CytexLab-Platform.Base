# Пакет CytexLab.Kernel.Base (CytexLab-Platform.Base)
Пакет CytexLab-Platform.Base предоставляет базовые утилитные классы и типы для разработки на платформе CytexLab-Platform
## Файлы
1. Types.hpp
2. ExChar.hpp
## Классы
1. EncoderUTF
2. ExChar
## Типы
1. INT?, UINT? (INT8, UINT8, INT16, UINT16 и подобные для 8, 16, 32, 64)
2. BOOL
3. CHAR, UCHAR
4. WCHAR
5. ExChar
6. LPINT?, LPUINT? (LPINT8, LPUINT8, и подобные для 8, 16, 32, 64)
7. LPBOOL
8. LPCHAR, LPUCHAR
9. LPWCHAR
10. LPCINT?, LPCUINT? (LPCINT8, LPCUINT8, и подобные для 8, 16, 32, 64)
11. LPCBOOL
12. LPCCHAR, LPCUCHAR
13. LPCWCHAR
## Утилиты
1. EncoderUTF::ToUtf8(LPCINT32 Sym, LPINT8 Code)
2. EncoderUTF::ToUtf16(LPCINT32 Sym, LPINT16 Code);
3. EncoderUTF::ToUtf32(LPCINT8 Sym, LPINT32 Code);
4. EncoderUTF::ToUtf32(LPCINT16 Sym, LPINT32 Code);
# Сборка
## Linux
Зависимости:
  1. Clang  
  2. LLVM (ld.lld, lld)  
### Debug
Debug сборка включает в себя отладочную информацию и/или отладочные символы в файле Debug.CytexLab.Kernel.Base.* (Также допускается вариант создания файла рядом с библиотекой: Debug.CytexLab.Kernel.Base.pdb)  
`./build.sh -b Debug` - Для запуска сборки с автовыбором Debug как режима сборки  
`./build.sh` - После запуска, необходимо будет выбрать Debug как режим сборки  
`./build.sh -b Debug -h` - Для запуска сборки с автовыбором Debug как режима сборки и тихим режимом  

### Release
Release сборка включает в себя максимальную оптимизацию по скорости и/или убирает отладочную информацию и отладочные символы  
`./build.sh -b Release` - Для запуска сборки с автовыбором Release как режима сборки  
`./build.sh` - После запуска, необходимо будет выбрать Release как режим сборки  
`./build.sh -b Release -h` - Для запуска сборки с автовыбором Release как режима сборки и тихим режимом
## Windows
Будет позже :)
# Лицензии
Платформа CytexLab-Platform и ее пакеты (в том числе библиотеки, тест и исполняемые файлы) распространяются под лицензией MPL 2.0 (Mozilla Public License, см. LICENSE и/или на сайте Mozilla)