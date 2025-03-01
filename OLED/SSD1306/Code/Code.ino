
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Определяем размеры экрана
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Определяем пин для сброса (если не используется, укажите -1)
#define OLED_RESET -1

// Создаем объект дисплея
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Инициализация серийного монитора для отладки
  Serial.begin(9600);
 Serial.println("SSD1306 TEST");
  // Инициализация дисплея
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // Очистка экрана
  display.clearDisplay();

  // Отображение текста
  display.setTextSize(2); // Размер текста
  display.setTextColor(SSD1306_WHITE); // Цвет текста
  display.setCursor(10, 10); // Установка курсора
  display.println(F("Hello!")); // Вывод текста
  display.display(); // Обновление дисплея

  delay(2000); // Задержка на 2 секунды

  // Пример рисования простых фигур
  display.clearDisplay();
  display.drawRect(10, 10, 50, 30, SSD1306_WHITE); // Прямоугольник
  display.fillCircle(100, 32, 10, SSD1306_WHITE); // Заполненный круг
  display.display();

  delay(2000); // Задержка на 2 секунды
}

void loop() {
    // 1. Зажечь все пиксели на 5 секунд
  display.fillRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_WHITE);
  display.display();
  delay(5000);

  // 2. Шахматный порядок пикселей
  display.clearDisplay();
  for (int y = 0; y < SCREEN_HEIGHT; y++) {
    for (int x = 0; x < SCREEN_WIDTH; x++) {
      if ((x + y) % 2 == 0) {
        display.drawPixel(x, y, SSD1306_WHITE);
      }
    }
  }
  display.display();
  delay(1000);

  // 3. Зажигать пиксели рядами
  display.clearDisplay();
  for (int y = 0; y < SCREEN_HEIGHT; y++) {
    display.drawLine(0, y, SCREEN_WIDTH - 1, y, SSD1306_WHITE);
    display.display();
    delay(50); // Задержка между отрисовкой рядов
  }

  // Завершение цикла: возвращаемся к первому тесту
  delay(1000);


  delay(500);

  display.clearDisplay();
  display.display();
  
  delay(500);
}
