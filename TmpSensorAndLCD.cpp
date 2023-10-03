#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inisialisasi objek lcd dengan alamat I2C 0x27, 2 baris, 16 karakter

int sensorPin = A0;  // Pin analog untuk membaca sensor suhu

void setup() {
  pinMode(sensorPin, INPUT);  // Mengatur sensorPin sebagai input
}

void loop() {
  int rawValue = analogRead(sensorPin);  // Membaca nilai analog dari sensor suhu
  float voltage = (rawValue / 1024.0) * 5.0;  // Menghitung tegangan dari nilai analog
  float temperatureC = (voltage - 0.5) * 100.0;  // Menghitung suhu dalam derajat Celsius

  lcd.init();  // Inisialisasi layar LCD
  lcd.backlight();  // Mengaktifkan pencahayaan layar LCD
  lcd.setCursor(0, 0);  // Mengatur posisi kursor di baris 1, kolom 1
  lcd.print("Hallo Semua");  // Menampilkan pesan "Hallo Semua" di layar LCD
  lcd.setCursor(0, 1);  // Mengatur posisi kursor di baris 2, kolom 1
  lcd.print("Suhu: ");  // Menampilkan teks "Suhu: " di layar LCD
  lcd.setCursor(6, 1);  // Mengatur posisi kursor di baris 2, kolom 7
  lcd.print(temperatureC);  // Menampilkan suhu dalam derajat Celsius di layar LCD
  lcd.print(" C");  // Menampilkan satuan "C" di layar LCD

  delay(2000);  // Delay selama 2 detik sebelum membaca suhu berikutnya
}
