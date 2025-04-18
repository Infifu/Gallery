using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.Remoting.Contexts;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.VisualStyles;
using Gallery_GUI;

namespace Gallery_GUI
{
    public partial class GalleryGUI : Form
    {
        private string currBTN = null;
        private PipeServer enginePipe;
        String[] fileLocations;
        int currFile = 0;

        public GalleryGUI()
        {
            InitializeComponent();
            customizeDesing();
            this.Visible = true;
            enginePipe = new PipeServer();
            this.Load += Form1_Load;
            enginePipe.Connect();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void customizeDesing()
        {
            userPanel.Visible = false;
            panelAlbum.Visible = false;
            picPanel.Visible = false;
        }

        private void hideSubMenu()
        {
            if (userPanel.Visible == true)
                userPanel.Visible = false;
            if (panelAlbum.Visible == true)
                panelAlbum.Visible = false;
            if (picPanel.Visible == true)
                picPanel.Visible = false;
            
        }

        private void ShowSubMenu(Panel subMenu)
        {
            if (subMenu.Visible == false)
            {
                hideSubMenu();
                subMenu.Visible = true;
            }
            else
            {
                subMenu.Visible = false;
            }
        }



        private void disableKeys()
        {
            this.addPicBTN.Enabled = false;
            this.RemovePicBTN.Enabled = false;
            this.listPictures.Enabled = false;

            this.addPicBTN.BackColor = Color.FromArgb(60, 65, 75);
            this.RemovePicBTN.BackColor = Color.FromArgb(60, 65, 75);
            this.listPictures.BackColor = Color.FromArgb(60, 65, 75);
        }

        private void enableKeys()
        {
            this.addPicBTN.Enabled = true;
            this.RemovePicBTN.Enabled = true;
            this.listPictures.Enabled = true;

            this.addPicBTN.BackColor = Color.FromArgb(85, 100, 120);
            this.RemovePicBTN.BackColor = Color.FromArgb(85, 100, 120);
            this.listPictures.BackColor = Color.FromArgb(85, 100, 120);
        }

        private void label1_Click(object sender, EventArgs e)
        {
            this.EntryPANEL.Visible = true;
            this.UserName.Text = "Enter your username:";
            currBTN = this.CreateUserBTN.Text;
        }

        private void AcceptBTN_MouseClick(object sender, MouseEventArgs e)
        {
            String content = this.userENTRY.Text;
            String message = null;
            if (currBTN == this.CreateUserBTN.Text)
            {
                message = "14#" + content.Length.ToString().PadLeft(2, '0') + "#" + content;
            }
            else if (currBTN == this.RemoveUserBTN.Text)
            {
                message = "15#" + content.Length.ToString().PadLeft(2, '0') + "#" + content;
            }
            else if (currBTN == this.listuseralbumsBTN.Text)
            {
                message = "06#" + content.Length.ToString().PadLeft(2, '0') + "#" + content;
            }

            if (content != null)
            {
                String response = this.enginePipe.SendMessageToClient(message);
                if (currBTN == this.listuseralbumsBTN.Text && response != "1")
                {
                    this.DataShow.Visible = true;
                    this.DataLabel.Text = response;
                }
            }
            System.Threading.Thread.Sleep(1000);
            this.EntryPANEL.Visible = false;
        }

        private void ListOfUsers_Click(object sender, EventArgs e)
        {
            this.DataShow.Visible = true;
            string message = "16#00#";
            string response;
            response = this.enginePipe.SendMessageToClient(message);
            this.DataLabel.Text = response;
        }

        private void Close_Click(object sender, EventArgs e)
        {
            this.DataShow.Visible = false;
        }

        private void DataLabel_Click(object sender, EventArgs e)
        {

        }

        private void RemoveUserBTN_Click(object sender, EventArgs e)
        {
            this.EntryPANEL.Visible = true;
            this.UserName.Text = "Enter your user ID:";
            currBTN = this.RemoveUserBTN.Text;
        }

        private void listalbumsBTN_Click(object sender, EventArgs e)
        {
            this.DataShow.Visible = true;
            string message = "05#00#";
            string response;
            response = this.enginePipe.SendMessageToClient(message);
            this.DataLabel.Text = response;
        }

        private void createAlbumBTN(object sender, EventArgs e)
        {
            this.AlbumPanel.Visible = true;
            this.currBTN = CreateALBUM.Text;
            this.AlbumEntry1.Text = "Enter user ID: ";
            this.AlbumEntry2.Text = "Enter album name: ";
        }

        private void albumEnter_Click(object sender, EventArgs e)
        {
            String content = this.albumtxt1.Text;
            String content2 = this.albumtxt2.Text;
            String message = null;
            if (currBTN == CreateALBUM.Text)
            {
                message = "01#" + content.Length.ToString().PadLeft(2, '0') + "#" + content + "#";
                message += content2.Length.ToString().PadLeft(2, '0') + "#" + content2;
            }
            else if (currBTN == open_album.Text)
            {
                message = "02#" + content.Length.ToString().PadLeft(2, '0') + "#" + content + "#";
                message += content2.Length.ToString().PadLeft(2, '0') + "#" + content2;
            }
            else if (currBTN == delete_albumBTN.Text)
            {
                message = "04#" + content.Length.ToString().PadLeft(2, '0') + "#" + content + "#";
                message += content2.Length.ToString().PadLeft(2, '0') + "#" + content2;
            }
            if (content != null)
            {
                String response = this.enginePipe.SendMessageToClient(message);
                if (currBTN == open_album.Text)
                {
                    if (response == "0")
                    {
                        currAlbumLabel.Text = "Current Album: " + content2;
                        enableKeys();
                    }
                }
            }

            System.Threading.Thread.Sleep(1000);
            this.AlbumPanel.Visible = false;
        }

        private void open_album_Click(object sender, EventArgs e)
        {
            this.AlbumPanel.Visible = true;
            this.currBTN = open_album.Text;
            this.AlbumEntry1.Text = "Enter user ID: ";
            this.AlbumEntry2.Text = "Enter album name: ";
        }

        private void closeAlbumBTN_Click(object sender, EventArgs e)
        {
            String message = "03#";
            String respomse = this.enginePipe.SendMessageToClient(message);
            this.currAlbumLabel.Text = "Current Album: None";
            disableKeys();
        }

        private void delete_albumBTN_Click(object sender, EventArgs e)
        {
            this.AlbumPanel.Visible = true;
            this.currBTN = delete_albumBTN.Text;
            this.AlbumEntry1.Text = "Enter user ID: ";
            this.AlbumEntry2.Text = "Enter album name: ";
        }

        private void listuseralbumsBTN_Click(object sender, EventArgs e)
        {
            this.EntryPANEL.Visible = true;
            this.UserName.Text = "Enter your user ID:";
            currBTN = this.listuseralbumsBTN.Text;
        }

        private void AlbumLabel_Click(object sender, EventArgs e)
        {

        }

        private void addPicBTN_Click(object sender, EventArgs e)
        {
            OpenFileDialog fileDialog = new OpenFileDialog();
            fileDialog.Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif";

            DialogResult result = fileDialog.ShowDialog();
            if (result == DialogResult.OK)
            {
                string path = fileDialog.FileName;
                string fileName = fileDialog.SafeFileName;
                string message;

                message = "07#" + fileName.Length.ToString().PadLeft(2, '0') + "#" + fileName + "#";
                message += path.Length.ToString().PadLeft(2, '0') + "#" + path;
                String respomse = this.enginePipe.SendMessageToClient(message);
            }
            else
            {

            }
        }

        private void listPictures_Click(object sender, EventArgs e)
        {
            this.imageListPanel.Visible = true;
            string message = "10#";
            string response = this.enginePipe.SendMessageToClient(message);
            String[] fileLocationsORIGINAL = response.Split('|');
            fileLocations = new string[fileLocationsORIGINAL.Length - 1];
            Array.Copy(fileLocationsORIGINAL, fileLocations, fileLocationsORIGINAL.Length - 1);

            this.pictureBox1.ImageLocation = fileLocations[0];
        }

        private void Next_Click(object sender, EventArgs e)
        {
            currFile = (currFile + 1) % fileLocations.Length;
            this.pictureBox1.ImageLocation = fileLocations[currFile];
        }

        private void Prev_Click(object sender, EventArgs e)
        {
            currFile = (currFile - 1 + fileLocations.Length) % fileLocations.Length;
            this.pictureBox1.ImageLocation = fileLocations[currFile];
        }

        private void CloseImage_Click(object sender, EventArgs e)
        {
            this.imageListPanel.Visible = false;
            this.tagListPanel.Visible = false;
            this.tagListLabel.Visible = false;
        }

        private void RemovePicBTN_Click(object sender, EventArgs e)
        {
            OpenFileDialog fileDialog = new OpenFileDialog();
            fileDialog.Filter = "Image Files|*.jpg;*.jpeg;*.png;*.bmp;*.gif";

            DialogResult result = fileDialog.ShowDialog();
            if (result == DialogResult.OK)
            {
                string fileName = fileDialog.SafeFileName;
                string message;

                message = "08#" + fileName.Length.ToString().PadLeft(2, '0') + "#" + fileName;
                String respomse = this.enginePipe.SendMessageToClient(message);
            }
            else
            {

            }
        }

        private void TagUserBTN_Click(object sender, EventArgs e)
        {
            TagPanel.Visible = true;
        }

        private void aceeptTAG_Click(object sender, EventArgs e)
        {
            string picName = Path.GetFileName(fileLocations[currFile]);
            string userID = this.tagBox.Text;
            string message;

            if (currBTN == button6.Text)
            {
                message = "12#" + picName.Length.ToString().PadLeft(2, '0') + "#" + picName + "#";
                message += userID.Length.ToString().PadLeft(2, '0') + "#" + userID;
                string response = this.enginePipe.SendMessageToClient(message);
                this.TagPanel.Visible = false;
            }
            else
            {
                message = "11#" + picName.Length.ToString().PadLeft(2, '0') + "#" + picName + "#";
                message += userID.Length.ToString().PadLeft(2, '0') + "#" + userID;
                string response = this.enginePipe.SendMessageToClient(message);
                this.TagPanel.Visible = false;
            }
        }

        private void label1_Click_2(object sender, EventArgs e)
        {

        }

        private void listTags_click(object sender, EventArgs e)
        {
            string picName = Path.GetFileName(fileLocations[currFile]);
            string message;
            message = "13#" + picName.Length.ToString().PadLeft(2, '0') + "#" + picName;
            string response = this.enginePipe.SendMessageToClient(message);
            this.tagListLabel.Text = response;
            this.tagListPanel.Visible = true;
            this.tagListLabel.Visible = true;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ShowSubMenu(userPanel);
        }

        private void albumMenu_Click(object sender, EventArgs e)
        {
            ShowSubMenu(panelAlbum);
        }

        private void picMenu_Click(object sender, EventArgs e)
        {
            ShowSubMenu(picPanel);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            TagPanel.Visible = true;
            currBTN = button6.Text;
        }
    }
}
