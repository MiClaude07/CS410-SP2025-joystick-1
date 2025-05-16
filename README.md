# CS410-SP2025-joystick-1

Capstone project for CS410. We will be developing a joystick controller!

## User Manual:

### Controller Setup

1. Connect controller to ESP32 Microcontroller as such: (Component --> ESP32 Input)

- Left Joystick:
  GRD --> GRD
  V --> 3V3
  X --> 32
  Y --> 35
  Z --> 33

- Right Joystick:
  GRD --> GRD
  V --> 3V3
  X --> 39 (VN)
  Y --> 36 (VP)
  Z --> 34\

- Left Button:
  GRD --> GRD
  V --> 3V3
  B --> 27

- Right Button:
  GRD --> GRD
  V --> 3V3
  B --> 25

2. Connect Controller to Computer. ESP32 Microcontroller lights should turn on.

3. Upload **joystickController.ino** code to ESP32 Mictocontroller.

4. Open Bluetooth Settings on Computer and pait controller.

5. Check controller is functioning properly at https://miclaude07.github.io/CS410-SP2025-joystick-1/src/webpage/

### Steam Setup

1. Complete **Controller Setup**

2. Open Steam: https://store.steampowered.com/about/download

3. In the top left of the client click: **Steam**

4. In the drop down click: **Settings**

5. In the side bar click: **Controller**

6. The Controller should appear. Click **Begin Test** and then **Setup Device Inputs**. Follow screen prompts. The controller should now be recognized in Steam. (Optional): Open **Steam Big Picture Mode** and try to navigate the menus with controller.

7. To play a game: Return to **Library** and choose a game. On the right, click the controller icon.

8. Make sure **Steam Input** is enabled.

### Astroids But Awesome

1. Download **Asteroids But Awesome.exe** from https://github.com/MiClaude07/CS410-SP2025-joystick-1/blob/main/Asteroids%20But%20Awesome.exe

2. Complete **Steam Setup**

3. In Steam, on the top bar click **Games**

4. From the drop down click **Add a Non-Steam Game to My Library**

5. Add **Asteroids But Awesome**

6. Find the game in your library

7. Edit Gamepad Layout as so:
  
   Left Joystick Up - Up Arrow
   
   Left Joystick Down - Down Arrow
   
   Left Joystick Left - Left Arrow
   
   Left Joystick Right - Right Arrow
   
   Right Controller Button - Left Mouse Click 
