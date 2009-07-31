;(in-package :cs-user)
(use-package "GDI")
(defun f ()
  (let* ((hwnd (GDI::CreateFontA (- (GDI::GetDeviceCaps hdc LOGPIXELSY))
                                 0 0 0 GDI::FW_BOLD T NIL NIL GDI::ANSI_CHARSET
                                 GDI::OUT_TT_PRECIS GDI::CLIP_DEFAULT_PRECIS
                                 GDI::PROOF_QUALITY GDI::VARIABLE_PITCH
                                 "Times New Roman"))
         (x (/ (GDI::GetSystemMetrics GDI::SM_CXSCREEN) 2))
         (y (/ (GDI::GetSystemMetrics GDI::SM_CYSCREEN) 2))
         (hold (GDI::SelectObject hdc hfont)))
     (GDI::SetTextAlign hdc (logior GDI::TA_CENTER GDI::TA_BASELINE))
     (GDI::SetBkMode hdc GDI::TRANSPARENT)
     (GDI::SetTextColor hdc (GDI::make-rgb 0 0 #xff))
     (GDI::TextOutA hdc x y "HELLO WORLD" 11)
     (GDI::SelectObject hdc hold)
     (GDI::DeleteObject hfont)))

(defun onDraw (hdc) (GDI::TextOutA hdc 0 0 "HELLO WORLD cb" 11))
(defun onKeyDown (wparam lparam) (quit))

(defun main ()
  (GDI::add-callbacks GDI::WM_NCCREATE 
                      (list (cons GDI::WM_PAINT #'onDraw)
                            (cons GDI::WM_KEYDOWN #'onKeyDown)))
  (let* ((cn "HelloWorld")
         (wndclass 
          (or (GDI::FindAtomA cn) 
              (GDI::GlobalFindAtomA cn)
              (GDI::RegisterClassA
               (GDI::make-wndclass 0 0 0 GDI::*hinstance* NIL
                                   (GDI::LoadCursorA NIL (GDI::GetIDC GDI::IDC_ARROW))
                                   (GDI::GetStockObject GDI::WHITE_BRUSH)
                                   NIL cn))))
         (cr (GDI::make-createstruct 0 wndclass "HelloWorld"
                                     GDI::WS_POPUP 0 0 
                                     (/ (GDI::GetSystemMetrics GDI::SM_CXSCREEN) 2)
                                     (/ (GDI::GetSystemMetrics GDI::SM_CYSCREEN) 2)
                                     NIL NIL GDI::*hinstance* NIL))
         (win (GDI::CreateWindowIndirectA cr)))
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
