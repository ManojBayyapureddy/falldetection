# Falldetection using wearable sensor

<h1>Steps to Run:</h1>
<h4>•	Connect NodeMCU and MPU6050 using jumper wires on a bread board as per the circuit diagram given above.</h4>
<h4>•	Once the circuit is ready, connect the board to any port of your laptop.</h4></h4>
<h4>•	Open Arduino IDE, and open New Sketch and copy code to new sketch.</h4>
<h4>•	Add Wi-Fi SSID, password and Blynk app template ID and auth token in code (line 20,21).</h4></h4>
<h4>•	Now Click on ‘Select Board’ and select ‘NodeMCU 6050’ and respective port (COM3).</h4>
<h4>•	Click on Verify.</h4>
<h4>•	Click on upload.</h4>
<h4>•	Once the code is uploaded to 100%, the device is ready to test.</h4>
<h4>•	To test the device, pretend to walk slowly, and then suddenly drop the device. If the magnitude exceeds the threshold value, the device will activate the fall detection event and send an alert to the respective registered members.</h4>

<h1>Blynk Application Setup:</h1>
<h4>•	Download and Open Blynk application.</h4>
<h4>•	Click on ‘Menu’ and ‘Add New Device’ and select Quick Start Device</h4>
<h4>•	Click on Automations -> Add New Animation -> select Device State</h4>
<h4>•	 Now select Device ‘Quick Start Device’</h4>
<h4>•	Select amp and set amp is between 12 and 15.</h4>
<h4>•	Now select ‘Add action’ -> ‘Send app notification’ and give alert message.</h4>
<h4>•	Now click on Save.</h4>

