# Falldetection using wearable sensor
Steps to Run:
•	Connect NodeMCU and MPU6050 using jumper wires on a bread board as per the circuit diagram given above.
•	Once the circuit is ready, connect the board to any port of your laptop.
•	Open Arduino IDE, and open New Sketch and copy code to new sketch.
•	Add Wi-Fi SSID, password and Blynk app template ID and auth token in code (line 20,21).
•	Now Click on ‘Select Board’ and select ‘NodeMCU 6050’ and respective port (COM3).
•	Click on Verify.
•	Click on upload.
•	Once the code is uploaded to 100%, the device is ready to test.
•	To test the device, pretend to walk slowly, and then suddenly drop the device. If the magnitude exceeds the threshold value, the device will activate the fall detection event and send an alert to the respective registered members.
Blynk Application Setup:
•	Download and Open Blynk application.
•	Click on ‘Menu’ and ‘Add New Device’ and select Quick Start Device
•	Click on Automations -> Add New Animation -> select Device State
•	 Now select Device ‘Quick Start Device’
•	Select amp and set amp is between 12 and 15.
•	Now select ‘Add action’ -> ‘Send app notification’ and give alert message.
•	Now click on Save.

