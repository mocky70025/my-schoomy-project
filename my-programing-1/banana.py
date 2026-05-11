# ファイル名：generate_mouth_xml.py
# 実行すると haarcascade_mcs_mouth.xml を自動生成します

mouth_xml_url = 'https://raw.githubusercontent.com/opencv/opencv_contrib/master/modules/face/data/cascades/haarcascade_mcs_mouth.xml'
save_as = 'haarcascade_mcs_mouth.xml'

import urllib.request

try:
    print(f"ダウンロード中：{mouth_xml_url}")
    urllib.request.urlretrieve(mouth_xml_url, save_as)
    print(f"保存成功：{save_as}")
except Exception as e:
    print(f"エラーが発生しました：{e}")
