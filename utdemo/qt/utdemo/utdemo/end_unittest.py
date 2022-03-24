
import os
import codecs
from pre_unittest import find_pro
from pre_unittest import read_file_content_lines
from pre_unittest import get_modulename
from pre_unittest import get_dependent_heads
from pre_unittest import get_file_encoding

def read_content_lines(filename, enc):
    with codecs.open(filename, 'r', encoding=enc) as fr:
        filecontent = fr.readlines()
        return filecontent

def write_content(filename, enc, content):
    linezero = 0
    ff = bytes()
    with codecs.open(filename, 'w', encoding=enc) as fw:
        for l in content :
            if u"//private:\r\n" == l:
                fw.write("private:\r\n")
            else:
                fw.write(l)
            # if u"#define private public\r\n" == l :
            #     linezero += 1
            #     lbytes = l.encode(enc)
            #     ff = lbytes[0:3]
            #     continue
            # else:
            #     # if linezero == 1:
            #     lbytes = l.encode(enc)
            #     fw.write(lbytes.decode(enc))
            #     # else:
            #         # fw.write(l)
            #     linezero += 1

def revert_public_to_private(dependents):
    for dirname in dependents:
        dirname = dirname.strip().replace(' ', '').replace('\\','').replace('\n','')
        for entry in os.listdir(dirname):
            if '.h' == os.path.splitext(entry)[-1].lower():
                file_name = dirname + '/' + entry
                encod = get_file_encoding(file_name)
                # print(file_name + ' --> ' + encod)
                filecontent = read_content_lines(file_name, encod)
                write_content(file_name, encod, filecontent)

if __name__ == '__main__':
    testpro = find_pro()
    if '' != testpro:
        filecontent = read_file_content_lines(testpro)
        modulename = get_modulename(filecontent)
        dependent_heads = get_dependent_heads(filecontent, modulename)
        revert_public_to_private(dependent_heads)
    else:
        print('not found *.pro')
