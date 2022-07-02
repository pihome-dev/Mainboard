# piHOME Mainboard Firmware Revision 1.0

This is the official piHOME mainboard firmware

### Features

1. piHOME Connect Bus
2. Two Temperature Measurements
3. Two Motion Detections
4. air pressure measurement
5. humidity measurement
6. piHOME Display Connector
7. Standalone Control (UART)

# Build

1. Set configuration in config.h
2. Set pinconfiguration in pins.h
3. run 'make clean'
4. run 'make hex'
5. run 'make program' (Optionally)

# Instructions
Build instructions with images can be found here:

#### config.h

Different configuration values can be set in Config.h. The most important values are F_CPU and Outsorting.

*** Important

It is mandatory The F_CPU is set with the right CPU clock being set as it can otherwise come to an undesirable behavior.

  Setting|Value|Description
  --------|---|-------
  F_CPU|12000000 - 16000000|Set the CPU Frequency
  UART_BAUD_RATE|0-0|Data
  TIMERFREQ|0-0|Data
  TIMERPRE|0-0|Data
  SYSTEMTIME_SYNCTIME|0-0|Data
  
  Setting|Value|Description
  --------|---|-------
  FOTOSENSOR_DEFAULT_VALUE|12000000 - 16000000|Set the CPU Frequency
  LIGHT_BRIGHTNESS_DEFAULT_VALUE|0-0|Data
  FOTOSENSOR_DEFAULT_READINTERVAL|0-0|Data
  FOTOSENSOR_DEFAULT_READTOLERANCE|0-0|Data
  LIGHT_BRIGHTNESS_DEFAULT_ON|0-0|Data
  PIR_DEFAULT_VALUE|12000000 - 16000000|Set the CPU Frequency
  PIR_HARDWARE_RESET_TIME|0-0|Data
  DS1820_DEFAULT_READINTERVAL|0-0|Data
  BME280_DEFAULT_READINTERVAL|0-0|Data
  EEPROM_AUTOSAVE_TIME|0-0|Data
