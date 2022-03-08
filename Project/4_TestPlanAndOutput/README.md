## Test Plans
For this module we need to understand the different types of components used:

**1. Temperature Sensor (NTC type 10K).**

**2. Voltage Sensor (Connected to the Nickel contact of Li-ion Battery).**

* The first part is to test the thermistors, i.e Potentiometer at the top right of the project

![tempsens1](https://user-images.githubusercontent.com/98948359/157180629-1f6f3aa0-d6a0-46b5-a990-4e66063ffce7.png)

As you can see the 1st sensor is cranked all the way. As a result, the fan will rotate at higher speeds andthe contactor will switch.

![tempsenserror](https://user-images.githubusercontent.com/98948359/157181009-6379590a-227b-42ce-aa51-64d357a697d7.png)

![fanspeed_indication](https://user-images.githubusercontent.com/98948359/157181078-518b3cae-a9a0-474b-8dd0-8328d8d2d748.png)

![main_contactorrelay](https://user-images.githubusercontent.com/98948359/157181141-7db700ad-2a94-4ce5-b9d9-eefcff274fa5.png)

The same can be observed with the 2nd thermistor (i.e Potentiometer).

Now, We need to check the functioning of the Voltage sensing module

![voltagesens1less](https://user-images.githubusercontent.com/98948359/157182153-641668fd-a5ac-4b48-8308-528403e5b73b.png)

Here, the voltage sensing module is made up of a voltage divider circuit to prevent high voltage and current flow to the ADC terminals of ATMEGA328p.

![more4 3V](https://user-images.githubusercontent.com/98948359/157182352-ae696e5d-c1cd-456d-8f1c-6fe229d84d18.png)

Once the voltage rises above 4.2V the charging of batteries has been completed and the contactor needs to be switched.

![errorledvltsens](https://user-images.githubusercontent.com/98948359/157182560-f8073779-b50a-4a6c-9b60-04921cb4e402.png)

![contactvltsens](https://user-images.githubusercontent.com/98948359/157182633-c08c76ec-ea90-45f0-8d6f-537a3c9aa455.png)

**Note**: These are also well documented in the video which is available in the same folder and can give a better idea about the same.


