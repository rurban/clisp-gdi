;;; This should be created automatically by modprep the c-sources 
;;; from the embedded comments below the DEFUN line.

(setf (documentation 'GDI::CreateIconFromResource 'function)
"presbits - Buffer containing the icon or cursor resource bits. 
         These bits are typically loaded by calls to the LookupIconIdFromDirectory 
         (in Windows 95 you can also call LookupIconIdFromDirectoryEx) and 
         LoadResource functions. 
The return value is the foreign-pointer to the handle to the icon or cursor.")