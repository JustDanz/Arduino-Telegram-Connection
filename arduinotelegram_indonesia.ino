#include <ESP8266WiFi.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>

const char* ssid = "Nama_WiFi_Anda"; // Nama WiFi
const char* password = "Password_WiFi_Anda"; // Password WiFi
const char* telegramToken = "TOKEN_BOT_TELEGRAM"; // Token API dari Bot Telegram

WiFiClientSecure client;
UniversalTelegramBot bot(telegramToken, client);

unsigned long lastTimeBotRan;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  // Koneksi WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Menghubungkan ke WiFi...");
  }
  Serial.println("WiFi Terhubung");

  client.setInsecure();
}

void loop() {
  // Cek pesan dari bot setiap 2 detik
  if (millis() - lastTimeBotRan > 2000) {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages) {
      for (int i = 0; i < numNewMessages; i++) {
        String chat_id = String(bot.messages[i].chat_id);
        String text = bot.messages[i].text;

        // Balasan dari bot Telegram
        if (text == "/start") {
          bot.sendMessage(chat_id, "Halo, saya bot Arduino!", "");
        }
      }
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
}
