This section provides step-by-step instructions for preparing your development host for flashing the image to the device.

.. note::

    The following instructions assume you are using Ubuntu 22.04 LTS or Windows 10/11.

Install Git
-----------

Git is required to download the ``usb-tool``. Follow these steps to ensure it is installed:

1.  **Check if Git is installed:**
    Open a terminal and run the following command:

    .. code-block:: bash

       git --version

    If Git is installed, this command will output its version (e.g., ``git version 2.34.1``). If you see a version number, you can skip to the next section.

2.  **Install Git (Linux):**
    If Git is not installed (e.g., the command in step 1 returns an error like "command not found"), install it using the following commands on Ubuntu:

    .. code-block:: bash

       sudo apt update
       sudo apt install git

    You will be prompted for your password and asked to confirm the installation.

3. **Install Git (Windows):**
    Use the **Microsoft Store** to install Git:

    - Open the **Microsoft Store** application.
    - Search for **Git** and install the official version (usually listed as "Git for Windows").
    - Once installed, open **PowerShell** and verify the installation (refer to step 1).

Set up the usb-tool
-------------------

The ``usb-tool`` is required for flashing the device. To install it, clone the repository:

.. code-block:: bash

    git clone https://github.com/synaptics-astra/usb-tool.git

Installing the WinUSB Driver (Windows Only)
-------------------------------------------

The WinUSB driver is required on Windows to establish communication with the device's bootloader.

1. **Locate the driver files:**
   After cloning the ``usb-tool`` repository, navigate to the following directory:

   ``usb-tool\Synaptics_WinUSB_Driver``

2. **Install the driver:**
   Right-click on the ``SYNA_WinUSB.inf`` file and select **Install** from the context menu.

   This will install the necessary WinUSB driver for the device.

   .. note::

      For more detailed instructions, refer to the
      `official documentation <https://synaptics-astra.github.io/doc/v/1.6.0/linux/index.html#installing-the-winusb-driver-windows-only>`_.

Installing the VC++ Redistributable (Windows Only)
--------------------------------------------------

If you encounter errors related to missing libraries while using the flashing script, you may need to install
the Microsoft Visual C++ Redistributable package.

1. **Download the installer:**
   Visit the `Microsoft Visual C++ Redistributable download page
   <https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170>`_
   to get the latest supported version.

2. **Install the package:**
   Run the downloaded installer and follow the on-screen instructions to complete the installation.
