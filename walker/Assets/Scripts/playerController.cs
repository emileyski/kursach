using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class playerController : MonoBehaviour
{
    public int life_count;
    Animator animator;
    private Rigidbody2D rb;

    private GameObject weapon;

    private Joystick joystick;
    [SerializeField]
    private float speed;
    public bool isAlive = true;
    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
        animator = GetComponent<Animator>();
        joystick = GameObject.Find("Fixed Joystick").GetComponent<Joystick>();
        weapon = transform.Find("Weapon").gameObject;
    }

    void Update()
    {
        PlayerAnimation();
        if(isAlive) Move();
        Die();

    }
    void Move()
    {
        transform.position += new Vector3(speed * Time.deltaTime * joystick.Horizontal, speed * Time.deltaTime * joystick.Vertical, 0f);
        if (joystick.Horizontal != 0)
            transform.localScale = (joystick.Horizontal > 0) ? new Vector3(1, 1, 1) : new Vector3(-1, 1, 1);
    }

    void PlayerAnimation()
    {
        bool isRunning = (joystick.Horizontal != 0 || joystick.Vertical != 0) ? true : false;
        animator.SetBool("isRunning", isRunning);
    }
    private void OnTriggerEnter2D(Collider2D collision)
    {
        if(collision.gameObject.layer == 8)
        {
            life_count--;
            if (life_count <= 0)
                Invoke("SceneReload", 2f);
        }
        if (collision.tag == "currentRoom")
        {
            collision.GetComponentInParent<roomParameters>().activation();
        }
    }
    void SceneReload()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
    }
    void Die()
    {
        if(life_count <= 0)
        {
            isAlive = false;
            animator.SetTrigger("IsDead");
        }
    }

    public void shooting(bool isShoot)
    {
        weapon.GetComponent<weaponController>().attack(isShoot);
    }
    private void GettingHit()
    {

    }
}
