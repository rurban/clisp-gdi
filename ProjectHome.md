This modern (=case-sensitive) clisp package module
is a interface to gdi, the lowest level
ms windows graphics api (Graphics Device Interface). It is a work in progress,
and is copyright Dan Stanger 2002 and Reini Urban 2006-2009

It is licensed under the LGPL and all rights are assigned to the Free Software Foundation.

Old style:
```
(use-package "GDI")
(defun f ()
  (let* ((hdc (multiple-value-bind (retval h) (GDI::GetDC nil)
                 (if retval h (error "GetDC ~S" h))))
         (sy (multiple-value-bind (retval l)
                         (GDI::GetDeviceCaps hdc GDI::LOGPIXELSY)
                 (if retval l (error "GetDeviceCaps ~S" l))))
         (logfont (GDI::make-logfont
              (- sy) 0 0 0 GDI::FW_BOLD 1 0 0 GDI::ANSI_CHARSET
              GDI::OUT_TT_PRECIS GDI::CLIP_DEFAULT_PRECIS
              GDI::PROOF_QUALITY GDI::VARIABLE_PITCH
              "Times New Roman"))
         (hfont (multiple-value-bind (retval h)
                  (GDI::CreateFontIndirectA logfont)
                  (if retval h (error "CreateFontA ~S" h))))
         (x (/ (GDI::GetSystemMetrics GDI::SM_CXSCREEN) 2))
         (y (/ (GDI::GetSystemMetrics GDI::SM_CYSCREEN) 2))
         (hold (multiple-value-bind (retval h) (GDI::SelectObject hdc hfont)
                 (if retval h (error "GetDC ~S" h)))))
     (GDI::SetTextAlign hdc (logior GDI::TA_CENTER GDI::TA_BASELINE))
     (GDI::SetBkMode hdc GDI::TRANSPARENT)
     (GDI::SetTextColor hdc (GDI::make-rgb 0 0 #xff))
     (GDI::TextOutA hdc x y "HELLO WORLD" 11)
     (GDI::SelectObject hdc hold)
     (GDI::DeleteObject hfont))) 
```

New-style (in work):
```
(use-package "GDI")
(defun f ()
  (let* ((hdc (GDI::GetDC nil))
         (sy  (GDI::GetDeviceCaps hdc GDI::LOGPIXELSY))
         (logfont (GDI::make-logfont
              (- sy) 0 0 0 GDI::FW_BOLD 1 0 0 GDI::ANSI_CHARSET
              GDI::OUT_TT_PRECIS GDI::CLIP_DEFAULT_PRECIS
              GDI::PROOF_QUALITY GDI::VARIABLE_PITCH
              "Times New Roman"))
         (hfont (GDI::CreateFontIndirectA logfont))
         (x (/ (GDI::GetSystemMetrics GDI::SM_CXSCREEN) 2))
         (y (/ (GDI::GetSystemMetrics GDI::SM_CYSCREEN) 2))
         (hold (GDI::SelectObject hdc hfont)))
     (GDI::SetTextAlign hdc (logior GDI::TA_CENTER GDI::TA_BASELINE))
     (GDI::SetBkMode hdc GDI::TRANSPARENT)
     (GDI::SetTextColor hdc (GDI::make-rgb 0 0 #xff))
     (GDI::TextOutA hdc x y "HELLO WORLD" 11)
     (GDI::SelectObject hdc hold)
     (GDI::DeleteObject hfont)))
```

Problems:
modern (case-sensitive + inverted) modprep packages are not fully supported as of clisp-2.48. You need the patches in this module, the completer and the interner is still broken, and doc-strings are still missing from the functions, the automatic mod-prep'ed doc-string can be improved.

More outputSTRUCT funcs are needed - return structs as structs not as foreign pointer.

new-style:
All multiple return values are being re-written to omit the initial T for success.
The return value is always different from NIL, which indicates a failure.

Documentation:
The gdi.xml should get better generated from the sources. doc-strings should be added.