#include <ESP8266WiFi.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>

const char* ssid = "Your_WiFi_Name"; // WiFi Name
const char* password = "Your_WiFi_Password"; // WiFi Password
const char* telegramToken = "YOUR_TELEGRAM_BOT_TOKEN"; // Telegram Bot API Token

WiFiClientSecure client;
UniversalTelegramBot bot(telegramToken, client);

unsigned long lastTimeBotRan;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  // Connect to WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("WiFi Connected");

  client.setInsecure();
}

void loop() {
  // Check for messages from the bot every 2 seconds
  if (millis() - lastTimeBotRan > 2000) {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages) {
      for (int i = 0; i < numNewMessages; i++) {
        String chat_id = String(bot.messages[i].chat_id);
        String text = bot.messages[i].text;

        // Bot reply to Telegram
        if (text == "/start") {
          bot.sendMessage(chat_id, "Hello, I am an Arduino bot!", "");
        }
      }
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
}
