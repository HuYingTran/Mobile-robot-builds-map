import openpyxl

wb = openpyxl.load_workbook('./Book1.xlsx')
sheet_copy = wb.copy_worksheet(wb['Sheet1'])
sheet = wb['Sheet1 Copy']

for i in range(1, 10):
    sheet["A" + str(i)] = int(1)
    sheet["B" + str(i)] = int(2)
    sheet["C" + str(i)] = int(5)

wb.save('./Book1.xlsx')