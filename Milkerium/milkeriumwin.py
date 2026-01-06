from tkinter import Tk, Button
# Criando a janela principal
janela = Tk()
janela.title("Milkerium")
janela.geometry("400x300")
# Função chamada ao clicar no botão
def clique():
   print("YOUR MOTHERFUCKER")
# Adicionando um botão
botao = Button(janela, text="AIIIIIIIIINNNNNNNNN", command=clique)
botao.pack() # Posiciona o botão na janela
# Iniciando o loop principal
janela.mainloop()