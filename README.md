# Arduino Uno - Telegram Bot Integration

This project demonstrates how to connect an Arduino Uno to a Telegram bot using an ESP8266 module. The bot allows users to send commands through Telegram to interact with the Arduino Uno.

## Project Overview

This project utilizes:
- **Arduino Uno** for main processing
- **ESP8266** for WiFi connectivity
- **Universal Telegram Bot Library** for managing Telegram bot communications

By sending commands via Telegram, you can trigger responses from the bot in real-time.

## Features

- **WiFi Connectivity**: The ESP8266 module connects to a specified WiFi network.
- **Telegram Bot Messaging**: Users can interact with the Arduino by sending commands like `/start`.
- **Real-Time Responses**: The bot checks for new messages every 2 seconds.

## Components Required

- **Arduino Uno**
- **ESP8266 WiFi Module (ESP-01 or ESP-12E)**
- **Jumper Wires**
- **Internet Connection**

## Installation

1. Clone this repository:
    ```bash
    git clone https://github.com/JustDanz/arduino-telegram-bot.git
    ```
2. Open the `.ino` file in **Arduino IDE**.
3. 
4. Install the required libraries:
   - Open Arduino IDE.
   - Go to **Sketch > Include Library > Manage Libraries...**.
   - Install **Universal Telegram Bot** and **ESP8266WiFi** libraries.

## Setting Up the Telegram Bot

1. Open **Telegram** and search for **BotFather**.
2. Send the command `/newbot` to create a new bot and follow the instructions.
3. Save the **API Token** provided by BotFather.

## Configuration

1. In the Arduino code, update the following variables with your WiFi credentials and bot token:

   ```cpp
   const char* ssid = "Your_WiFi_Name";
   const char* password = "Your_WiFi_Password";
   const char* telegramToken = "Your_Telegram_Bot_Token";
   ```

## Wiring

1. Connect the **ESP8266** module to **Arduino Uno** as follows:
   - `VCC` to `3.3V`
   - `GND` to `GND`
   - `TX` to `RX`
   - `RX` to `TX`

2. Ensure proper power and grounding for ESP8266.

## Usage

1. Upload the code to **Arduino Uno**.
2. Open **Telegram** and send the `/start` command to your bot.
3. The bot will respond with "Halo, saya bot Arduino!".

## Troubleshooting

- **Bot not responding**: Check your WiFi connection and API Token.
- **Serial Monitor Debugging**: Use Arduino Serial Monitor to troubleshoot any issues.
