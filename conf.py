from sphinxawesome_theme.postprocess import Icons

# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = "Grinn Docs"
author = "Grinn sp. z o.o."
copyright = "%Y Grinn sp. z o.o. — All rights reserved."

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

templates_path = ["_templates"]
exclude_patterns = ["_build", "venv", ".venv"]
extensions = []

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_static_path = ["_static"]
html_css_files = ["custom.css"]
html_title = "Grinn"
html_baseurl = "https://grinn-global.github.io"
html_favicon = "_static/favicon.ico"
html_show_sphinx = False

# -- Options for HTML theme --------------------------------------------------
# https://sphinxawesome.xyz/how-to/configure/

html_theme = "sphinxawesome_theme"
html_permalinks_icon = Icons.permalinks_icon
html_theme_options = {
    "logo_light": "_static/logo.svg",
    "logo_dark": "_static/logo.svg",
    "show_scrolltop": True,
}
