Once the board is successfully flashed, you can connect to the device over a serial interface using any terminal emulator of your choice.

Connecting to the Device
------------------------

Ensure the board is powered on and connected via the Debug USB port.

1. **Identify the serial port.**

   Determine the serial port exposed by the device:

   .. code-block:: bash

      ls /dev/ttyUSB*

2. **Connect to the device.**

   Use a terminal emulator to connect to the serial port of the device:

   .. parsed-literal::

      minicom -D /dev/ttyUSB0 -b |BAUDRATE|

   .. note::
      If you encounter permission errors, you may need to add your user to the ``dialout`` group.

      Log out and log back in for the changes to take effect.

3. **Access the console.**

   Once connected, you should see the console output.
   If the device is already booted, press Enter to get a login prompt.
