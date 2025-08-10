This section provides step-by-step instructions for preparing your development host for flashing the image to the device.

.. note::

    The following instructions assume you are using Ubuntu 22.04 LTS.

Install Git
-----------

Git is required to download the ``usb-tool``. Follow these steps to ensure it is installed:

1.  **Check if Git is installed:**
    Open a terminal and run the following command:

    .. code-block:: bash

       git --version

    If Git is installed, this command will output its version (e.g., ``git version 2.34.1``). If you see a version number, you can skip to the next section.

2.  **Install Git (if not installed):**
    If Git is not installed (e.g., the command in step 1 returns an error like "command not found"), install it using the following commands on Ubuntu:

    .. code-block:: bash

       sudo apt update
       sudo apt install git

    You will be prompted for your password and asked to confirm the installation.

Set up the usb-tool
-------------------

The ``usb-tool`` is required for flashing the device. To install it, clone the repository:

.. code-block:: bash

    git clone https://github.com/synaptics-astra/usb-tool.git
