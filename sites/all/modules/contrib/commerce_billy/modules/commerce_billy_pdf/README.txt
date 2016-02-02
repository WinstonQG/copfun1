Commerce Billy PDF
******************
Enables PDF donwload of invoiced and canceled orders.

Installation
************

1. Dowload dompdf lib in place it into the libraries folder, e.g. sites/all/libraries/dompdf

Possible drush make file:
libraries[dompdf][download][type] = "get"
libraries[dompdf][download][url] = "https://github.com/dompdf/dompdf/releases/download/v0.6.1/dompdf-0.6.1.zip"
libraries[dompdf][directory_name] = "dompdf"
libraries[dompdf][destination] = "libraries"


2. Add dompdf fonts to public dir:

dompdf needs write access to its font directory.
Copy "libraries/dompdf/lib/fonts" to your public files directory:
  public://fonts (example: sites/default/files/fonts)

To check if everything is at the right place, you should find
  public://fonts/Courier.afm (for example at
  sites/default/files/fonts/Courier.afm).


Administration
**************
Go to: Store > Configuration > Billy invoice settings > PDF
        (/admin/commerce/config/billy-invoice/pdf)

Hooks
*****

Advanced users may want to take advantage of the hooks provided by the Commerce
Billy PDF module. There are two hooks intended to be used together in your own
custom module, to allow multiple PDF templates. Per default (without
implementing these hooks by other modules), only one PDF template (the default
one) can be configured (at the tab "Store > Configuration > Billy invoice
settings > PDF"). By implementing the provided hooks, you can add one or more
additional sub tab(s) to that tab, each representing a custom PDF template.
Which of the custom PDF templates should be applied to a given order can be
specified based on properties of the $order object, for example by the type of
a line item within the order. 

See inside the file "commerce_billy_pdf.api.php" how to implement the provided
hooks.


Troubles
********
- Invoice links returns "Error generating PDF invoice. Please contact the
  website administrator." :
    Check your watchdog which contains information about the exception. Usually
    fonts are not correctly installed.

Credits
*******
Matthias Hutterer (mh86)
Klaus Purer (klausi)
