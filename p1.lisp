;(in-package :cs-user)
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

#|
(trace GDI::CreateFontIndirectA)
(trace GDI::DeleteObject)
(trace GDI::GetDC)
(trace GDI::GetDeviceCaps)
(trace GDI::GetSystemMetrics)
(trace GDI::make-rgb)
(trace GDI::make-logfont)
(trace GDI::SelectObject)
(trace GDI::SetBkMode)
(trace GDI::SetTextAlign)
(trace GDI::SetTextColor)
(trace GDI::TextOutA)
|#

(f)

;; case tests:
;; (in-package :cs-user)(use-package "GDI")(setq lst '())(do-external-symbols (s (find-package 'gdi) lst) (push s lst))
;; (setq lst '())(do-symbols (s (find-package 'gdi) lst) (push s lst))
;; (in-package :user)(use-package "GDI")(setq lst '())(do-external-symbols (s (find-package 'gdi) lst) (push s lst))
;; ./clisp -K full -norc -q -x "(in-package :cs-user)(use-package :GDI)(setq lst '())(do-symbols (s (find-package 'gdi) lst) (push s lst))"
