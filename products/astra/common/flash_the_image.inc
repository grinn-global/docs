This section details the steps for flashing your device. Ensure you've completed the prerequisites and set up the ``usb-tool`` as described in the previous section.

.. note::
    To obtain the latest firmware image, either build it from source or download a prebuilt image.

    See previous sections for details on building or downloading the image.

Connect the Board
-----------------

Flashing |BOARD_NAME| requires:

* external |POWER_SOURCE_DESCRIPTION| power source,
* Debug USB port connected to the host PC.

|BOARD_IMAGE_PORTS|

Download Mode
-------------

To flash the |BOARD_NAME|, it must first be in **download mode**.

1. Locate the **RESET** and **USB_BOOT** buttons on your device (see the picture below).
2. Press and hold both buttons at the same time.
3. While still holding **USB_BOOT**, release **RESET**.
4. After a brief pause, release **USB_BOOT**.

|BOARD_NAME| should now be in download mode.

|BOARD_IMAGE_BUTTONS|

Flashing
--------

Once the ``usb-tool`` is ready and your device is in download mode, you can proceed with flashing the firmware.

1. **Navigate to the root directory of your Yocto build.**

   Open a new terminal (do not use the Grinn Yocto Docker container) and navigate to the root directory of your |BOARD_NAME| Yocto build.

   .. code-block:: bash

      cd /path/to/your/yocto/main/directory

2. **Execute the flashing process.**

   Use the ``flash-grinn-astra.sh`` helper script to flash your device, specifying the path to ``usb-tool`` and selecting the |BOARD_NAME| platform (|FLASH_SCRIPT_PLATFORM_SELECTOR|).
   The proper image will be selected from the Yocto build tree automatically:

   .. code-block:: bash

      ./src/meta-grinn-astra/scripts/flash-grinn-astra <path/to/usb-tool> <platform_selector>

   If you have a pre-built image to be flashed, you can specify the path to the image manually:

   .. code-block:: bash

      ./src/meta-grinn-astra/scripts/flash-grinn-astra <path/to/usb-tool> <platform_selector> <path/to/prebuilt/image>

   After the flashing is complete, an appropriate success message will appear in the script's output.


.. note::

   The script will display progress updates in your terminal.

   **Do not disconnect your device or interrupt the process until it completes successfully.**

Flashing a Prebuilt Image
-------------------------

If you have a prebuilt firmware image (in `.zip` format), you can easily flash it using the **Grinn Astra Flash** tool.

1. **Download and Extract**
    Download the prebuilt firmware archive (`.zip`) and extract it into a directory (e.g., `image/`).

2. **Launching the Application**
    Running the application on Linux requires administrator (root) privileges. Therefore, make sure to start it with
    the `sudo` prefix — both on Linux and on macOS.

    Open a terminal (Linux/macOS) and run:

    .. code-block:: bash

        sudo grinn-astra-flash

    Open a PowerShell (Windows) and run:

    .. code-block:: powershell

        grinn-astra-flash.exe

3. **Flashing**
    Use the `Select Image` button and choose the folder containing the image.

    After selecting the path, click Flash.

    .. image:: /_static/images/grinn-astra-flash/main-window.png
        :width: 50%
        :alt: Grinn Astra Flash - Main window

    The application will then wait for the device. If the device has not yet been put into boot mode, do so now as
    described in the `Download Mode` section.

    .. image:: /_static/images/grinn-astra-flash/waiting-for-device.png
        :width: 50%
        :alt: Grinn Astra Flash - Waiting for the device

    When the device is detected, the flashing process will begin.

    .. image:: /_static/images/grinn-astra-flash/flashing.png
        :width: 50%
        :alt: Grinn Astra Flash - Flashing

    Once the flashing process is complete, a message saying `Flashing Complete!` will appear. After that, you can close
    the application by clicking the X in the application’s title bar.

    .. image:: /_static/images/grinn-astra-flash/flashing-complete.png
        :width: 50%
        :alt: Grinn Astra Flash - Flashing complete

Troubleshooting
---------------

**Failed to boot device / Device not detected**

You might see messages such as:

.. code-block:: none

   Boot Failed: Timeout during boot, press RESET while holding USB_BOOT to try again
   Failed to Boot Device

To resolve this, ensure the device is correctly in download mode by repeating the steps in the ``Download Mode`` section. Also check your USB cable and connection.

**Flashing tool errors**

Make sure you are running the command with ``sudo``. Double-check the command syntax and the path to your firmware image.

For specific error messages, refer to the ``usb-tool`` documentation.

**Flashing fails mid-process**

Do not disconnect the device. Put it back into bootloader mode by repeating the ``Download Mode`` steps, then try flashing again.

If the problem continues, the firmware image might be corrupted or there could be a hardware issue with the device.
