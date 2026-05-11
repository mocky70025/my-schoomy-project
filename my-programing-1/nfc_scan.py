import sys
import nfc

def on_connect(tag):
    print("*** カードを検出しました ***", file=sys.stderr)
    if hasattr(tag, "idm"):
        print("IDm:", tag.idm.hex())
    else:
        print("Detected unsupported tag", file=sys.stderr)
    return False

try:
    clf = nfc.ContactlessFrontend("usb")
    print("FeliCaカードをかざして下さい", file=sys.stderr)
    clf.connect(rdwr={"on-connect": on_connect})
except Exception as e:
    print("Error:", e, file=sys.stderr)