import os
import io
import sys
import chardet
import codecs

def get_platform():
    return sys.platform

def is_linux():
    if 'linux' in get_platform():
        return True
    return False

def is_windows():
    if 'win' in get_platform():
        return True
    return False

def find_pro():
    filelists = os.listdir('./')
    # print(filelists)
    pro = ''
    for filename in filelists:
        if '.pro' == os.path.splitext(filename)[-1].lower()\
            and filename.lower().startswith('testgrgsp'):
            pro = filename
    return pro


def read_file_content_lines(pro_name):
    fp = open(pro_name, 'r')
    filecontent = fp.readlines()
    fp.close()
    return filecontent

def get_modulename(contentlines):
    modulename=''
    for line in contentlines:
        if "TARGET" == line.upper().replace(' ','').strip().split('=')[0]:
            modulename = line.replace(' ','').strip().split('=')[1][4:]
            break
    return modulename

def get_dependent_heads(contentlines, modulename):
    dependents = []
    isdepend = False
    _start = ' start'
    _end = ' end'
    _head_dependent = ' head dependent'
    for line in contentlines:
        if (modulename + _head_dependent + _start) in line:
            isdepend = True
            continue
        if (modulename + _head_dependent + _end) in line:
            isdepend = False
            break
        if isdepend:
            if modulename.lower() in line.lower():
                dependents.append(line)
    return dependents

def get_file_encoding(file):
    fenc = open(file, 'rb')
    data = fenc.read()
    fenc.close()
    return chardet.detect(data)['encoding']

def read_content_lines(filename, enc):
    with codecs.open(filename, 'r', encoding=enc) as fr:
        filecontent = fr.readlines()
        return filecontent

def write_content(filename, enc, content):
    flagline = 0
    bef = b'\xef'
    bbb = b'\xbb'
    bbf = b'\xbf'
    with codecs.open(filename, 'w', encoding=enc) as fw:
        for l in content :
            if u"private:\r\n" == l:
                commentprivate = u"//" + l
                fw.write(commentprivate)
            else:
                fw.write(l)
            # if flagline == 0:
            #     # print(l)
            #     lbytes = l.encode(enc)
            #     # print(lbytes)
            #     pripubstr = u"#define private public\r\n"
            #     pribytes = pripubstr.encode(enc)
            #     # print(lbytes[0])
            #     # print(lbytes[1])
            #     # print(lbytes[2])
            #     # print(bef)
            #     # print(bbb)
            #     # print(bbf)
            #     # print(lbytes[0] == bef)
            #     # print(lbytes[1] == bbb)
            #     # print(lbytes[2] == bbf)
            #     if (lbytes[0] == bef and lbytes[1] == bbb and lbytes[2] == bbf):
            #         contentbytes = pribytes + lbytes[3:]
            #     else:
            #         contentbytes = pribytes + lbytes
            #     # print(contentbytes)
            #     # fw.write(l)
            #     # fw.write(pripubstr)
            #     fw.write(contentbytes.decode(enc))
            #     flagline += 1
            #     continue
            # else:
            #     flagline += 1
            #     lbytes = l.encode(enc)
            #     fw.write(lbytes.decode(enc))
            #     # fw.write(l)
    
def change_private_to_public(dependents):
    for dirname in dependents:
        dirname = dirname.strip().replace(' ', '').replace('\\','').replace('\n','')
        # print(dirname)
        for entry in os.listdir(dirname):
            if '.h' == os.path.splitext(entry)[-1].lower():
                filename = dirname + '/' + entry
                encod = get_file_encoding(filename)
                filecontent = read_content_lines(filename, encod)
                write_content(filename, encod, filecontent)


if __name__ == '__main__':
    testpro = find_pro()
    if '' != testpro:
        filecontent = read_file_content_lines(testpro)
        modulename = get_modulename(filecontent)
        dependent_heads = get_dependent_heads(filecontent, modulename)
        change_private_to_public(dependent_heads)
    else:
        print('not found *.pro')
