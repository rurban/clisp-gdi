;(in-package :cs-cl-user)
(use-package "GDI")
(defun f ()
  (let* ((hwnd (multiple-value-bind (retval h)
                  (GDI::CreateFontA (- (GDI::GetDeviceCaps hdc LOGPIXELSY))
                                    0 0 0 GDI::FW_BOLD T NIL NIL GDI::ANSI_CHARSET
                                    GDI::OUT_TT_PRECIS GDI::CLIP_DEFAULT_PRECIS
                                    GDI::PROOF_QUALITY GDI::VARIABLE_PITCH
                                    "Times New Roman")
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

(defun onDraw (hdc)
     (GDI::TextOutA hdc 0 0 "HELLO WORLD" 11))

(defun onKeyDown (wparam lparam) (quit))

(defun main ()
  (GDI::add-callbacks GDI::WM_NCCREATE (list (cons GDI::WM_PAINT #'onDraw) 
                                             (cons GDI::WM_KEYDOWN #'onKeyDown)))
  (let* (
         (cn "HelloWorld")
         (wc (or (GDI::FindAtomA cn) (GDI::GlobalFindAtomA cn)
                 (multiple-value-bind (retval h)
                     (GDI::RegisterClassA
                      (GDI::make-wndclass 0 0 0 GDI::*hinstance* NIL
                                         (multiple-value-bind (retval h)
                                             (GDI::LoadCursorA NIL (GDI::GetIDC GDI::IDC_ARROW))
                                           (if retval h (error "LoadCursorA ~S" h)))
                                         (multiple-value-bind (retval h) (GDI::GetStockObject GDI::WHITE_BRUSH)
                                           (if retval h (error "GetStockObject ~S" h)))
                                         NIL cn))
                   (if retval h (error "RegisterClassA ~S" h)))))
         (cr (GDI::make-createstruct 0 wc "Hello World"
                                    GDI::WS_POPUP 0 0 (/ (GDI::GetSystemMetrics GDI::SM_CXSCREEN) 2)
                                    (/ (GDI::GetSystemMetrics GDI::SM_CYSCREEN) 2)
                                    NIL NIL GDI::*hinstance* NIL))
         (win (multiple-value-bind (retval h) (GDI::CreateWindowIndirectA cr)
                (if retval h (error "CreateWindowIndirectA ~S" h)))))
    (GDI::ShowWindow win GDI::SW_SHOWNORMAL)
    (GDI::UpdateWindow win)
    (GDI::MessageLoop)))

#|
(trace GDI::make-wndclass)
(trace GDI::make-createstruct)
(trace GDI::add-callbacks)
(trace onDraw)
(trace GDI::onCreate)
|#

(main)
