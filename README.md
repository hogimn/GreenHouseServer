# MDS-Embedded-Systems-Final-Project

### Entire Directory Tree
```
.
├── datasheet
├── drivers
│   ├── kernel-level
│   │   └── rtl8188C_8192C_usb_linux_v4.0.2_9000.20130911
│   │       ├── ...
│   ├── lib
│   │   └── inc
│   └── test-app
├── lib
│   └── inc
├── samples
└── src
    └── music

```

### Top Directory Structure ###
Directory | Explan.
----------|------------
***datasheet*** | Datasheets for Devices
***drivers*** | Kernel Device Driver and Their Library
***lib*** | Other General Library for main
***samples*** | Sample Code of Drivers
***src*** | Directory where main.c is

## Steps to build project ##
### 1. Change U-Boot NFS settings ###
In U-Boot terminal, do following settings.
```
set bootargs "root=/dev/nfs rw nfsroot=192.168.100.2:/nfsroot ip=192.168.100.102:192.168.100.2:192.168.100.1:255.255.255.0::eth0:off:netmask=255.255.255.0 console=ttySAC1,115200n81"
set ipaddr 192.168.100.102
set serverip 192.168.100.2
set gatewayip 192.168.100.1
saveenv (optional)
```

In your ubuntu host machine,    
network interface ip address which is connected to your MDS2450 board is to be 192.168.100.2.

### 2. Modify kernel source code to use platform device driver statically ###
Refer to [here](https://github.com/hogimn/MDS-Embedded-Systems-Final-Project/tree/main/drivers).

### 3. Build and deploy ###
In the top directory of project,
```
make
make deploy
```

### 4. Insert realtek driver module RTL8192CU ###
You should find your Wi-Fi SSID (Service Set IDentifier) and password.    
You can easily find your SSID using smartphone.    
The password is used to generate PSK (pre-shared key).    

***In your host***,
```
cd /nfsroot/root/
```

In "rtl_init" script,
change the ip address to your own to avoid address conflict.
```
ifconfig wlan0 192.168.0.210 -> ifconfig wlan0 192.168.0.x
```

I assumed that your network id is 192.168.0.x.
If not, modify rtl_init script like
```
ifconfig wlan0 "your.network.id.hostid"
```

Generate a WPA PSK from an ASCII passphrase for a SSID.
```
wpa_passphrase "your ssid" "password"  > wificonf.conf
```

***In your target***,
```
cd /root/
. rtl_init
```
If it loops log messages endlessly, it is pretty likely that you mistyped SSID or password in wpa_passphrase.

Test ping 
```
ping 192.168.0.1
```
### 5. Run your program ###
In your target,
```
cd /root/
./main
```
