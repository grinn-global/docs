This section details the steps for flashing your device. Ensure you've completed the prerequisites and set up the ``usb-tool`` as described in the previous section.

.. note::
    To obtain the latest firmware image, either build it from source or download a prebuilt image.

    See previous sections for details on building or downloading the image.

Connect the board
-----------------

Flashing |BOARD_NAME| requires:

* external |POWER_SOURCE_DESCRIPTION| power source,
* Debug USB port connected to the host PC.

|BOARD_IMAGE_PORTS|

Manually enabling download mode
-------------------------------

To flash the |BOARD_NAME|, it must first be in **download mode**. Follow these steps carefully:

* **Locate the buttons**: Find the **RESET** and **USB_BOOT** buttons on your device. Refer to picture below for details.
* **Enter bootloader sequence**:
    * **Press and hold** both the **RESET** and **USB_BOOT** buttons simultaneously.
    * While still holding **USB_BOOT**, **release RESET**.
    * Wait a moment, then **release USB_BOOT**.

|BOARD_NAME| should now be in download mode.

|BOARD_IMAGE_BUTTONS|

Flashing
--------

Once the ``usb-tool`` is ready and your device is in download mode, you can proceed with flashing the firmware.

* **Navigate to the root directory of your Yocto build**
    Open new terminal (do not use Grinn Yocto Docker container) and navigate to the root directory of your |BOARD_NAME| Yocto build.

    .. code-block:: bash

        cd /path/to/your/yocto/main/directory

* **Execute the flashing process**:
    Use the ``flash-grinn-astra.sh`` helper script to flash your device, specifying the path to ``usb-tool`` and selecting |BOARD_NAME| platform (|FLASH_SCRIPT_PLATFORM_SELECTOR|).
    Proper image will be selected from Yocto build tree automatically:

    .. code-block:: bash

        ./src/meta-grinn-astra/scripts/flash-grinn-astra </path/to/your/usb-tool> <platform_selector>

    If you have a pre-built image to be flashed you can specify path to the image manually:

    .. code-block:: bash

        ./src/meta-grinn-astra/scripts/flash-grinn-astra </path/to/your/usb-tool> <platform_selector> [/path/to/pre/built/image]

.. note::

   * **Monitor the flashing process**: The script will display progress updates in your terminal. **Do not disconnect your device or interrupt the process** until it completes successfully.
   * **Verify the flashing (optional but recommended)**: After the flashing is complete, an appropriate success message will appear in the script's output.

Troubleshooting
---------------

* **Failed to boot device / Device not detected**:
    * **Common Messages**:
        * "Boot Failed: Timeout during boot, press RESET while holding USB_BOOT to try again"
        * "Failed to Boot Device"
    * **Solution**:
        * Confirm your device is correctly in download mode by repeating the steps in the ``Manually enabling download mode`` section.
        * Check your USB cable and connection.

* **Flashing tool errors**:
    * Ensure you are running the command with ``sudo``.
    * Double-check the command syntax and the path to your firmware image.
    * Refer to the ``usb-tool``'s documentation or its GitHub repository for specific error messages.

* **Flashing fails mid-process**:
    * **Do not disconnect the device**.
    * Put the device back into bootloader mode by repeating the steps in the ``Manually enabling download mode section`` and attempt to re-flash.
    * If the issue persists, your firmware image might be corrupted, or there could be a hardware issue with your device.
