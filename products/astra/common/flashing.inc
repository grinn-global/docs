This section details the steps for flashing your device. Ensure you've completed the prerequisites and set up the ``usb-tool`` as described in previous sections.

Putting the Device into Bootloader Mode
---------------------------------------

To flash the device, it must first be in **bootloader mode**. Follow these steps carefully:

.. note::
   Ensure device is powered on and connected to the development host.

* **Locate the buttons**: Find the **RESET** and **USB_BOOT** buttons on your device. If you're unsure of their location, consult your device's hardware documentation.
* **Enter bootloader sequence**:
    * **Press and hold** both the **RESET** and **USB_BOOT** buttons simultaneously.
    * While still holding **USB_BOOT**, **release RESET**.
    * Wait a moment, then **release USB_BOOT**.

Device should now be in bootloader mode.

Flashing
---------------------------

Once the ``usb-tool`` is ready and your device is in bootloader mode, you can proceed with flashing the firmware.

* **Navigate to the ``usb-tool`` repository**:
    Open your terminal and navigate to the root directory of the ``usb-tool`` repository that you cloned during the setup steps. For example:

    .. code-block:: bash

        cd /path/to/your/usb-tool

* **Execute the flashing command**:
    Use the ``astra-update`` executable with ``sudo`` to flash your device, specifying the path to your firmware image:

    .. code-block:: bash

        sudo ./bin/linux/x86_64/astra-update --flash </path/to/your/image>

.. note::
   Replace </path/to/your/image> with actual directory. Your firmware image should be located in the ``tmp/deploy/images/grinn-astra-1680-<board>/SYNAIMG`` directory if your build process completed successfully.

* **Monitor the flashing process**: The ``astra-update`` tool will display progress updates in your terminal. **Do not disconnect your device or interrupt the process** until it completes successfully.

* **Verify the flashing (optional but recommended)**: After the flashing is complete, an appropriate success message will appear in the ``usb-tool``'s output.

Troubleshooting
---------------

* **Failed to boot device / Device not detected**:
    * **Common Messages**:
        * "Boot Failed: Timeout during boot, press RESET while holding USB_BOOT to try again"
        * "Failed to Boot Device"
    * **Solution**:
        * Confirm your device is correctly in bootloader mode by repeating the steps in the "Putting the Device into Bootloader Mode" section.
        * Check your USB cable and connection.

* **Flashing tool errors**:
    * Ensure you are running the command with ``sudo``.
    * Double-check the command syntax and the path to your firmware image.
    * Refer to the ``usb-tool``'s documentation or its GitHub repository for specific error messages.

* **Flashing fails mid-process**:
    * **Do not disconnect the device**.
    * Put the device back into bootloader mode by repeating the steps in the "Putting the Device into Bootloader Mode" section and attempt to re-flash.
    * If the issue persists, your firmware image might be corrupted, or there could be a hardware issue with your device.