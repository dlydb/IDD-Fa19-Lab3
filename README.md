# Data Logger (and using cool sensors!)

*A lab report by Ziyu Liu.*

## In The Report

Include your responses to the bold questions on your own fork of [this lab report template](https://github.com/FAR-Lab/IDD-Fa18-Lab2). Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

For this lab, we will be experimenting with a variety of sensors, sending the data to the Arduino serial monitor, writing data to the EEPROM of the Arduino, and then playing the data back.

## Part A.  Writing to the Serial Monitor
 
**a. Based on the readings from the serial monitor, what is the range of the analog values being read?**

0-1023
 
**b. How many bits of resolution does the analog to digital converter (ADC) on the Arduino have?**

10 bits

## Part B. RGB LED

**How might you use this with only the parts in your kit? Show us your solution.**

We can wire three LEDs in red, green and blue to replace the RGB LED. Also connect a resistor with each of the LED.

## Part C. Voltage Varying Sensors 
 
### 1. FSR, Flex Sensor, Photo cell, Softpot

**a. What voltage values do you see from your force sensor?**

The voltage is between 0 - 990 when a 10k resistor is in series.

**b. What kind of relationship does the voltage have as a function of the force applied? (e.g., linear?)**

The relationship is positive logarithmic. The voltage changes significantly when force is low. When the force is high, the voltage changes slow.

**c. Can you change the LED fading code values so that you get the full range of output voltages from the LED when using your FSR?**

We can convert the reading value(A0) from 0 - 990 to 0 - 255 with a linear transformation function: y = 3.88x.

**d. What resistance do you need to have in series to get a reasonable range of voltages from each sensor?**

10k resistor for both photo cell and softpot.

**e. What kind of relationship does the resistance have as a function of stimulus? (e.g., linear?)**

The relationship for both resistor is linear.

### 2. Accelerometer
 
**a. Include your accelerometer read-out code in your write-up.**

[read-out code](https://github.com/dlydb/IDD-Fa19-Lab3/blob/master/partd.ino)

### 3. IR Proximity Sensor

**a. Describe the voltage change over the sensing range of the sensor. A sketch of voltage vs. distance would work also. Does it match up with what you expect from the datasheet?**

**b. Upload your merged code to your lab report repository and link to it here.**

## Optional. Graphic Display

**Take a picture of your screen working insert it here!**

[Graphic Display](https://youtu.be/-sZHsRWXc6M)

## Part D. Logging values to the EEPROM and reading them back
 
### 1. Reading and writing values to the Arduino EEPROM

**a. Does it matter what actions are assigned to which state? Why?**

Yes. If there are three states, we cannot go from state 0 to state 2 or state 2 to state 0. For example, we have three state clear, read and write. When we are at clear state, we have to pass read if we want to access write state. Similarly, we also have to pass read state when we go from write to clear. So, the sequence of state matters. 

**b. Why is the code here all in the setup() functions and not in the loop() functions?**

Because we only want each state to process once.

**c. How many byte-sized data samples can you store on the Atmega328?**

1024 bytes. 

**d. How would you get analog data from the Arduino analog pins to be byte-sized? How about analog data from the I2C devices?**

The analog data is read from 0 to 1024 which is 10 bit. To convert the value to a 8 bit value, we can use a linear equation to map from 0-1024 to 0-255. However, the conversion may lower the accuracy due to the lost of some digit. For I2C, we can also map the reading to byte-size.

**e. Alternately, how would we store the data if it were bigger than a byte? (hint: take a look at the [EEPROMPut](https://www.arduino.cc/en/Reference/EEPROMPut) example)**

**Upload your modified code that takes in analog values from your sensors and prints them back out to the Arduino Serial Monitor.**

### 2. Design your logger
 
**a. Insert here a copy of your final state diagram.**

### 3. Create your data logger!
 
**a. Record and upload a short demo video of your logger in action.**
