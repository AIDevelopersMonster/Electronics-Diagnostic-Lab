const int buttonPin = A0;  // Все кнопки подключены к A0
const int buttonThresholds[] = {30, 150, 360, 535, 760};  // Пороговые значения для кнопок

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);  // Запуск монитора порта с битрейтом 9600
}

void loop() {
  // Считывание значения с пина A0
  int buttonValue = analogRead(buttonPin);

  // Определение, какая кнопка нажата
  int buttonIndex = getButtonIndex(buttonValue);

  if (buttonIndex != -1) {  // Если кнопка нажата
    // Преобразование значения в напряжение (для Arduino с 5V)
    float voltage = buttonValue * (5.0 / 1023.0);

    // Вывод значений на монитор порта
    Serial.print("Button ");
    Serial.print(buttonIndex + 1);  // Выводим номер кнопки
    Serial.print(" pressed. ADC Value: ");
    Serial.print(buttonValue);  // Значение АЦП
    Serial.print("\tVoltage: ");
    Serial.print(voltage, 3);  // Напряжение на пине A0 (с точностью до 3 знаков)
    Serial.println(" V");
  }

  delay(500);  // Пауза для обновления значений
}

// Функция для определения индекса кнопки
int getButtonIndex(int value) {
  for (int i = 0; i < 5; i++) {  // У нас 5 кнопок
    if (value < buttonThresholds[i]) {
      return i;  // Возвращаем индекс кнопки
    }
  }
  return -1;  // Кнопка не нажата
}
