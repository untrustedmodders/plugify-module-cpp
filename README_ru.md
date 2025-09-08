[![English](https://img.shields.io/badge/English-%F0%9F%87%AC%F0%9F%87%A7-blue?style=for-the-badge)](README.md)

# Модуль языка C++ для Plugify

Модуль языка C++ для Plugify позволяет разработчикам писать плагины на C++ для фреймворка Plugify. Этот модуль обеспечивает бесшовную интеграцию C++ плагинов, позволяя загружать и управлять ими динамически через ядро Plugify.

## Возможности

- **Поддержка плагинов на C++**: Пишите плагины на C++ и легко интегрируйте их с фреймворком Plugify.
- **Автоматическая экспортируемость**: Удобный экспорт и импорт методов между плагинами и языковым модулем.
- **Инициализация и завершение работы**: Обрабатывайте запуск, инициализацию и завершение плагина с помощью специальных событий модуля.
- **Взаимодействие между языками**: Общение с плагинами, написанными на других языках, через автоматически генерируемые интерфейсы.

## Начало работы

### Требования

- Компилятор C++ с поддержкой стандарта C++20  
- Установленный фреймворк Plugify

### Установка

#### Вариант 1: Установка через менеджер плагинов Plugify

Вы можете установить модуль языка C++ с помощью менеджера плагинов Plugify, выполнив следующую команду:

```
bash
plg install plugify-module-cpp
```

#### Вариант 2: Ручная установка

1. Установите зависимости:

   a. Windows  
   > Настройка [CMake-инструментов через Visual Studio Installer](https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio#installation)

   b. Linux:
   ```sh
   sudo apt-get install -y build-essential cmake ninja-build
   ```

   c. Mac:
   ```sh
   brew install cmake ninja
   ```

2. Клонируйте репозиторий:

   ```bash
   git clone https://github.com/untrustedmodders/plugify-module-cpp.git --recursive
   cd plugify-module-cpp
   ```

3. Сборка модуля языка C++:

   ```bash
   mkdir build && cd build
   cmake ..
   cmake --build .
   ```

### Использование

1. **Интеграция с Plugify**

   Убедитесь, что модуль языка C++ находится в той же директории, что и установка Plugify.

2. **Разработка плагинов на C++**

   Разрабатывайте плагины на C++ с использованием API Plugify. Смотрите [руководство по созданию плагина на C++](https://untrustedmodders.github.io/languages/cpp/first-plugin) для подробных инструкций.

3. **Сборка и установка плагинов**

   Соберите ваши C++ плагины и поместите скомпилированные библиотеки в директорию, доступную для ядра Plugify.

4. **Запуск Plugify**

   Запустите фреймворк Plugify — он автоматически загрузит ваши C++ плагины.

## Пример

```c++
#include <plugify/cpp_plugin.hpp>
#include <plugin_export.h>
#include <iostream>

class ExamplePlugin : public plugify::IPluginEntry {
public:
	void OnPluginStart() override {
		std::cout << "Example Start!" << std::endl;
	}

	void OnPluginEnd() override {
		std::cout << "Example End!" << std::endl;
	}
} g_examplePlugin;

EXPOSE_PLUGIN(PLUGIN_API, &g_examplePlugin)
```

## Документация

Для получения подробной информации о написании плагинов на C++ с использованием фреймворка Plugify обратитесь к [документации Plugify](https://untrustedmodders.github.io).

## Участие в разработке

Не стесняйтесь вносить свой вклад, создавая issues или отправляя pull request'ы. Мы рады любым идеям и отзывам!

## Лицензия

Этот модуль языка C++ для Plugify распространяется по лицензии [MIT](LICENSE).
