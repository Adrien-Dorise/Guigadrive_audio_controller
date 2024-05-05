# Guigadrive project
The Guigadrive is my work on mixing an electric guitar with a video game console. It takes inspiration from the design of the SEGA Megadrive for the body of the guitar. 

A Raspberry PI is inserted inside the body to allow the emulation of old gen consoles (from NES, to PS1, and with of course, the Megadrive). 

In addition, an audio controller is designed to be able to play games while playing the guitar.


## To do list:
1. [ ✔️ ] Design of the guitar's body using SolidWorks
2. [ ✔️ ] Finding the guitar's neck
3. [ ✔️ ] Buying all the hardware (tuners, bridge, humbucker...)
4. [ ✔️ ] 3D print of the guitar's body
5. [ ✔️ ] Painting
6. [ ✔️ ] Setup of the Raspberry Pi
7. [ ✔️ ] Assembly of all parts
8. [ ✔️ ] Design of an audio controller
9. [ ✔️ ] Programmation of the Audio Controller
10. [ ✔️ ] Playing Mario while playing Mario

### Design of the guitar's body
The design is made on SolidWorks. The body is composed of two main pieces. The top and the bottom, to be able to fit all electronics and the Rasepberry PI later on.
On the pictures below, you have an idea of what is the end result on CAD.

<p float="left">
<img width="500" alt="Screenshot 2022-11-01 194343" src="https://user-images.githubusercontent.com/71883623/199316232-ca8360bb-4bd3-45e1-b9d3-a76f2b54db88.png" />
<img width="500" alt="Screenshot 2022-11-01 194247" src="https://user-images.githubusercontent.com/71883623/199316228-f81b6d8c-4adb-42f1-9e4f-ad6d1cfd1947.png" />
</p>
<p align="left">
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

### Audio controller
Finally, the last step is to design a controller that is able to pick up the sound of the guitar and transfer it as an input to the Raspberry PI.
An ESP32 is used to convert the frequency to an input. The code is available here. 

To amplify the signal, an A-class amplifier is built as shown on the pictures.

**How to use:**  
When using the controller, the input signal must be calibrated. To do so, a 10s tempo is performed at startup, then the signal is sampled and the average is used as the calibration value.  
From there, when a signal is detected, a DFT is performed. The user has to manually input the map frequency <-> output in the "press_key" function.  


<p float="left">
<img width="450" alt="Screenshot 2022-11-01 211410" src="https://github.com/Adrien-Dorise/Guigadrive_audio_controller/assets/71883623/3499c3ad-8fc8-4cbc-9a7a-8a198061ee9f">
</p>

<p float="left">
<img src="https://github.com/Adrien-Dorise/Guigadrive_audio_controller/assets/71883623/20f0cc77-7c21-4692-89fe-db8eb032dbeb" width=30% height=30% />
<img src="https://github.com/Adrien-Dorise/Guigadrive_audio_controller/assets/71883623/44dc1357-4591-43ba-b0a5-b1edb9cd3006" width=30% height=30% />
<img src="https://github.com/Adrien-Dorise/Guigadrive_audio_controller/assets/71883623/9379d48f-44b4-409f-9bd9-601d06980825" width=30% height=30% />
</p>

<p float="left">
<img src="https://github.com/Adrien-Dorise/Guigadrive_audio_controller/assets/71883623/eb1acf1d-943c-4d12-8e7c-0eb581dcd935" width=30% height=30% />
<img src="https://github.com/Adrien-Dorise/Guigadrive_audio_controller/assets/71883623/e55c964c-6c77-41b7-bda2-975f50ac68d4" width=30% height=30% />
<img src="https://github.com/Adrien-Dorise/Guigadrive_audio_controller/assets/71883623/1bf52a89-a167-4811-b308-41263e0e1016" width=30% height=30% />
</p>


