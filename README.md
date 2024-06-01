# Guardian Wheels: Smart Vehicle Security & Alert System (Using GSM/LTE (A7670C) Module, Mobile App and Arduino)

## ABSTRACT
  This project offers a straightforward but efficient way to stop **unwanted access to a vehicle** by **notifying the owner** promptly as the attempt is detected. 

  An Arduino UNO board, a buzzer, an **A7670C LTE module**, an HC 05 Bluetooth module, and a GPS Module are the primary components of the system. 

  The security elements of the system are controlled by the user through the use of an **Android app**, which gives them access to the system. 

  If the system is triggered, it alerts the owner an individual is attempting to input a key without the owner's authorization. It triggers a **buzzer alarm** to alert people in the vicinity 
of the illicit entry and uses the LTE module to start a conversation with the owner through SMS. 
The LTE module is configured to call the owner's phone number. 
Through a smartphone app or a dedicated Bluetooth device, the owner can **remotely enable or disable the security system** based on their preference. 
Along with current/live location information of the vehicle through the GPS Module.

  All things considered, this car security system provides a straightforward yet efficient means of preventing unauthorized entry and quickly alerting the owner to any possible 
security breaches.

## COMPONENTS REQUIRED
1. A7670C LTE module [(Link)](https://www.graylogix.in/product/sim-a7670c-4g-lte-ttl-modem)
2. Arduino UNO 
3. Hc-05 Bluetooth module 
4. Buzzer 
5. LED Bulb
6. Push Button
7. Bread Board 
8. Connecting/Jumper Wires 

> [!TIP]
> The A7670C LTE module can also be bought at local electronics shop (I had bought this way).

> [!IMPORTANT]
> Please be aware that there are multiple A7670C models. I haven't tested my code on other
models except my own.

> [!WARNING]
> The above link to the A7670C LTE module is for reference purpose only. Kindly, proceed at your own risk.

## FLOWCHART
![image](https://github.com/shravanthk05/Guardian-Wheels/assets/156297076/5d6250a9-1489-44ed-9e0f-29ed76b8ceaf)

## CIRCUIT CONNECTIONS
![Wheel Guardian](https://github.com/shravanthk05/Guardian-Wheels/assets/156297076/d121cf15-9954-447b-a778-ded9d45afba4)

## SETUP
![image](https://github.com/shravanthk05/Guardian-Wheels/assets/156297076/e49f6239-ea36-4aa9-a1d7-5638ea668251)

## HOW TO DO?
1. Give connections as per the circuit diagram.
2. Upload Arduino code into the Arduino Uno board.
3. Download the app file above in the repository (Built with the help of MIT APP BUILDER). 
4. Connect the app to the HC-05 Bluetooth module (Refer to the video link in the credits below).
5. Press the ON button in the app to activate the alarm system once connected.
6. When the alarm is on, if the pushbutton is pressed, the alarm will go off and the SMS and call function will be activated (Refer to the Demo Video).

## CREDITS
1) [Code and connections](https://forum.arduino.cc/t/arduino-code-for-4g-lte-sim-a7670c-development-board/1087180)
2) [Bluetooth App](https://www.youtube.com/watch?v=aQcJ4uHdQEA&t=1429s)

> [!NOTE]
> As you know, there are already many projects containing the same features (GSM Module, Call and SMS features) but ours uses a LTE(4G) module making it suitable for current situation
> where many 2G and 3G communication services are being shutdown. Also usage of an mobile app for this kind of application is also not done before (In the context of Arduino mini projects).

Thank you! For any queries and help regarding the projects contact to the E-Mail shravanthk05@gmail.com

