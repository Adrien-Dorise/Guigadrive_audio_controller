# Guigadrive project
The Guigadrive is my work on mixing an electric guitar with a video game console. It takes inspiration from the design of the SEGA Megadrive for the body of the guitar. 

A Raspberry PI is inserted inside the body to allow the emulation of old gen consoles (from NES, to PS1, and with of course, the Megadrive). 

In addition, an audio controller is designed to be able to play games while playing the guitar.


## To do list:
1. Design of the guitar's body using SolidWorks: **OK**
2. Finding the guitar's neck: **OK**
3. Buying all the hardware (tuners, bridge, humbucker...): **OK**
4. 3D print of the guitar's body: **OK**
5. Painting: **OK**
6. Setup of the Raspberry Pi: **OK**
7. Assembly of all parts: **OK**
8. Design of an audio controller: **In progress**

### Design of the guitar's body
The design is made on SolidWorks. The body is composed of two main pieces. The top and the bottom, to be able to fit all electronics and the Rasepberry PI later on.
On the pictures below, you have an idea of what is the end result on CAD.

<p float="left">
<img width="460" alt="Screenshot 2022-11-01 194343" src="https://user-images.githubusercontent.com/71883623/199316232-ca8360bb-4bd3-45e1-b9d3-a76f2b54db88.png" />
<img width="500" alt="Screenshot 2022-11-01 194247" src="https://user-images.githubusercontent.com/71883623/199316228-f81b6d8c-4adb-42f1-9e4f-ad6d1cfd1947.png" />
</p>
<p align="center">
<img width="500" alt="Screenshot 2022-11-01 194531" src="https://user-images.githubusercontent.com/71883623/199316222-fc39d7d7-8c94-4114-bd49-0c56a2f90965.png" />
</p>

### Buying hardware + neck + setup of Raspberry
All these parts were find on specialised shops for music instruments

### 3D print + painting
The guitar was printed by a freelance. Because of the size, it was tedious to find someone willing to do it while not being to expensive. 
(I had quote around 1500euros. Quite expensive for a solo project...). 

I finally found a very nice and professional 3d printer to make my piece in a reasonable budget. Go check out its website, it is worth it ! 
(https://www.hephaprint.fr/) To save a little more, I agreed to remove the filling by myself, and oh boy, there was a lot!

The dimensions were correctly calculated to welcome the Raspbery in its new home.

<p float="left">
<img src="https://user-images.githubusercontent.com/71883623/199322310-b65f4b08-e7ad-4e34-a0c0-aa7e9c16c9af.jpg" width=30% height=30% />
<img src="https://user-images.githubusercontent.com/71883623/199322313-454d080c-eee6-4dca-b726-41aebe4904b8.jpg" width=30% height=30% />
<img src="https://user-images.githubusercontent.com/71883623/199315646-3c076a50-2191-4a2b-8221-e1e9cb0b973c.jpg" width=30% height=30% />

</p>

<p float="left">
<img src="https://user-images.githubusercontent.com/71883623/199315611-86084882-f9de-489d-9ade-855f4f375e34.jpg" width=30% height=30% />
<img src="https://user-images.githubusercontent.com/71883623/199315621-99968b8c-fce8-4739-b7f3-408f26d7ee28.jpg" width=30% height=30% />
<img src="https://user-images.githubusercontent.com/71883623/199315633-0c7f8473-4e63-4bcc-b21f-275aee66affe.jpg" width=30% height=30% />
</p>

<p align="center">
<img src="https://user-images.githubusercontent.com/71883623/199315624-7f45f16f-37a3-41fb-987c-4e6f2ed2eaba.jpg" width=70% height=70%>
</p>

### Assembly of all parts + test of the Guigadrive
After everything is setup, the guitar can be plugged in with HDMI to a TV or a vide projector. Also, it is compatible with USB controllers such as PS4 or Xbox controllers.
On the picture, the Guigadrive is connected to a video projector.

<p float="left">
<img src="https://user-images.githubusercontent.com/71883623/199316544-a1866eda-82b6-4d67-b826-d59df3c0a765.jpg" width=30% height=30% />
<img src="https://user-images.githubusercontent.com/71883623/199315651-b44ac036-d101-46f4-96f6-4d35e91322e6.jpg" width=30% height=30% />
<img src="https://user-images.githubusercontent.com/71883623/199324852-8088f6da-d2a4-4909-95aa-e28f89d8880d.jpg" width=35% height=35% />
</p>

### Audio controller (in progress)
Finally, the last step is to design a controller that is able to pick up the sound of the guitar and transfer it as an input to the Raspberry PI.
An Arduino DUE is used to convert the frequency to an input. The code is available here. 

To amplify the signal, an A-class amplifier is built as shown on the pictures.

* Solder the amplifer 
* Design the case of the Arduino + amplifier 
* Print the case
* Play Metal Slug

<p float="left">
<img width="450" alt="Screenshot 2022-11-01 211410" src="https://user-images.githubusercontent.com/71883623/199332110-3164c570-1301-4ddb-b5c8-9a1369f56410.png">
<img src="https://user-images.githubusercontent.com/71883623/199315654-9b5e13a0-7474-45fd-a804-501091f6cdd1.jpg" width=50% height=50% />
</p>
