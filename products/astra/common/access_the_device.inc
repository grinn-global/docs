Once the board is successfully flashed, you can access it through the graphical environment or via an ADB connection.

Graphical Environment
---------------------

The Weston display server is installed and running in the default configuration.

Simply connect a monitor to the device to access the graphical environment.

ADB Connection
--------------

Ensure the board is powered on and connected via the Debug USB port.

1. **List ADB devices.**

   Use the following command to list all connected ADB devices:

   .. parsed-literal::

      adb devices

2. **Access the device.**

   You can access the device's shell using the following command:

   .. parsed-literal::

      adb shell
